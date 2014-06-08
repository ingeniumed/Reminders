#include "AppModel.h"

#include <bb/data/JsonDataAccess>
#include <bb/pim/calendar/CalendarEvent>
#include <bb/pim/calendar/CalendarService>

using namespace bb::cascades;
using namespace bb::pim::calendar;

//constructor
AppModel::AppModel(QObject *parent)
{
	setParent (parent);

}

//destructor
AppModel::~AppModel()
{
	// nothing here
}

//saves data and returns true to signal it was successful
bool AppModel::saveData()
{
	//creates an instance of jda and then saves the data to the path specified which would be the json file
	JsonDataAccess jda;
	jda.save(myRemindersData,myJsonDataPath);

	//checks errors
	if (jda.hasError()){
		bb::data::DataAccessError error = jda.error();
		qDebug() << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
		return false;
	}

	return true;
}

//moves the file to the data folder in order to gain read and write access
bool AppModel::jsonToDataFolder()
{
	QStringList pathSplit = myJsonAssetsPath.split("/");
	QString fileName = pathSplit.last();
	QString dataFolder = QDir::homePath();

	//data folder file's path
	myJsonDataPath = dataFolder + "/" + fileName;
	QFile newFile(myJsonDataPath);

	//checks if this an update or an entirely new file being created
	if (!newFile.exists()) {
		QString appFolder(QDir::homePath());
		appFolder.chop(4);
		QString originalFileName = appFolder + myJsonAssetsPath;
		QFile originalFile(originalFileName);

		//ensures if the created file and an already existing file are the same or not just in case
		if (originalFile.exists()) {
			return originalFile.copy(myJsonDataPath);
		} else {
			qDebug() << "Error: failed to copy file data because base file does not exist!";
			return false;
		}
	}

	return true;
}

//Set the asset path for the json data file
void AppModel::setJsonAssetPath(const QString jsonAssetPath)
{
	if (myJsonAssetsPath.compare(jsonAssetPath)!=0) {
		JsonDataAccess jda;

		//emit the Json asset path for other function to use
		myJsonAssetsPath = jsonAssetPath;
		emit jsonAssetPathChanged(jsonAssetPath);

		if (jsonToDataFolder()) {

			//copy the file's contents into the the list no matter if its newly created or already existing
			myRemindersData = jda.load(myJsonDataPath).value<QVariantList>();

			if (jda.hasError()) {
				bb::data::DataAccessError error = jda.error();
				qDebug() << "JSON loading error: " << error.errorType () << ": " << error.errorMessage();
				return ;
			}

			checkIfListIsFull();
		}
	}
}

void AppModel::setFilter(const QString filter)
{
    if (myFilter.compare(filter) != 0) {
        QVariantList filteredListData;

        //remove old stuff
        clear();

        // Populate a list with the items that has the corresponding status.
        foreach(QVariant v, myRemindersData) {
        if(v.toMap().value("completion") == filter) {
           filteredListData << v;
           append(v.toMap());
         }
        }

        // Update the filter property and emit the signal.
        myFilter = filter;
        emit filterChanged(filter);
    }
}

QString AppModel::filter()
{
    return myFilter;
}

//return the asset path
QString AppModel::jsonAssetPath()
{
	return myJsonAssetsPath;
}

//set if the task has been completed or not
void AppModel::setCompletionStatus(const QVariantList RemindersList, const QString newCompletionStatus)
{
	for (int i = RemindersList.count() - 1; i >= 0; i--) {

	        // Get the item at the index path at position i in the selection list.
	        QVariantList indexPath = RemindersList.at(i).toList();
	        QVariant modelItem = data(indexPath);

	        // Two indices are needed, the index of the item in the data list and
	        // the index of the item in the current model.
	        int itemDataIndex = myRemindersData.indexOf(modelItem);
	        int itemIndex = indexPath.last().toInt();

	        // Update the item in the list of data.
	        QVariantMap itemMap = myRemindersData.at(itemDataIndex).toMap();
	        itemMap["completion"] = newCompletionStatus;
	        myRemindersData.replace(itemDataIndex, itemMap);

	        // Since the item status was changed it is removed from the model and
	        // consequently it is removed from the current list shown by the app.
	        removeAt(itemIndex);
	    }
	    saveData();
}

void AppModel::deleteListItem(const QVariant item)
{
	    // Get the indices of the item in the model and in the data list.
	    QVariantMap itemMap = item.toMap();
	    int itemDataIndex = myRemindersData.indexOf(itemMap);
	    int itemIndex = indexOf(itemMap);

	    // And replace the item in both the model and the data list.
	    myRemindersData.removeAt(itemDataIndex);
	    removeAt(itemIndex);

	    saveData();
}

void AppModel::deleteListItems(const QVariantList RemindersList)
{
    for (int i = RemindersList.count() - 1; i >= 0; i--) {

        // Get the item at the index path at position i in the selection list.
        QVariantList indexPath = RemindersList.at(i).toList();
        QVariant modelItem = data(indexPath);

        // Two indices are needed, the index of the item in the data list and
        // the index of the item in the current model.
        int itemDataIndex = myRemindersData.indexOf(modelItem);
        int itemIndex = indexPath.last().toInt();

        // Remove the item from the data list and from the current data model items.
        myRemindersData.removeAt(itemDataIndex);
        removeAt(itemIndex);

        saveData();
    }

    checkIfListIsFull();
}

void AppModel::addListItem(const QString itemText, const QString itemIndex)
{
    QVariantMap itemMap;
    itemMap["index"] = QVariant(itemIndex);
    itemMap["text"] = QVariant(itemText);
    itemMap["completion"] = QVariant("todo");

    //check to make sure item is added at the end of the list officially
    if (indexOf(itemMap) == -1) {
    	if (myFilter.compare("todo")==0){
    		//add the new item at the top of the list
    		insert(0, itemMap);
    	}

        // Add the new item to the data list.
        myRemindersData.insert(0, itemMap);
        saveData();
    }

    // A new item has been added check to see if the max limit has been reached.
    checkIfListIsFull();
}

//set completion status of individual item
void AppModel::setICompletionStatus (const QVariant item, const QString completionStatus)
{
	 // Get the indices of the item in the model and in the data list.
	    QVariantMap itemMap = item.toMap();
	    int itemDataIndex = myRemindersData.indexOf(itemMap);
	    int itemIndex = indexOf(itemMap);

	    // Update the title.
	    itemMap["completion"] = completionStatus;

	    // And replace the item in both the model and the data list.
	    myRemindersData.replace(itemDataIndex, itemMap);
	    replace(itemIndex, itemMap);

	    saveData();
}

void AppModel::editListItem(const QVariant item, const QString newItemText, const QString newItemIndex)
{
    // Get the indices of the item in the model and in the data list.
    QVariantMap itemMap = item.toMap();
    int itemDataIndex = myRemindersData.indexOf(itemMap);
    int itemIndex = indexOf(itemMap);

    // Update the title.
    itemMap["index"] = newItemIndex;
    itemMap["text"] = newItemText;

    // And replace the item in both the model and the data list.
    myRemindersData.replace(itemDataIndex, itemMap);
    replace(itemIndex, itemMap);

    saveData();
}

bool AppModel::listIsFull(){
    return myListIsFull;
}

void AppModel::checkIfListIsFull()
{
    // Check if the bucket is full or not, if the status changes update the property.
    if (myRemindersData.count() < maxItems) {

        // Only emit the signal if the property actually changed.
        if(myListIsFull) {
            myListIsFull = false;
            emit myListIsChanged(myListIsFull);
        }

    	} else if (!myListIsFull) {
    		if(!myListIsFull) {
    			myListIsFull = true;
    			emit myListIsChanged(myListIsFull);
    		}
    	}
}
