#ifndef APPMODEL_H_
#define APPMODEL_H_

#include <bb/cascades/QListDataModel>
#include <bb/data/JsonDataAccess>
#include <QtNetwork/QNetworkReply>

using namespace bb::data;

typedef bb::cascades::QListDataModel<QVariantMap> RemindersListModel;

class AppModel: public RemindersListModel
{
	Q_OBJECT

	Q_PROPERTY(QString filter READ filter WRITE setFilter NOTIFY filterChanged)

	Q_PROPERTY(QString jsonAssetPath READ jsonAssetPath WRITE setJsonAssetPath NOTIFY jsonAssetPathChanged)

	Q_PROPERTY(bool listIsFull READ listIsFull NOTIFY myListIsChanged)

	public:
	    AppModel(QObject *parent = 0);
	    ~AppModel();

	    /**
	     * Returns the current filter set on the model, there are three
	     * valid filters "incomplete", "completed".
	     *
	     * @return A QString with the current filter.
	     */
	     QString filter();

	    /**
	     * Sets the current filter that is used to populate the model with data.
	     * It can be one of: "incomplete", "completed". If filter which is
	     * not one those three is set the data model will be empty.
	     *
	     * @param filter The new filter that should be used when loading data.
	     */
	     void setFilter(const QString filter);

	    /**
	     * Returns the relative file path to the JSON file in the assets folder. Note
	     * that this path will only be used the first time the application launches.
	     * The file will then be moved to the application data folder, so that it is
	     * possible to write to the file.
	     *
	     * @return The assets path to the JSON file for the reminders list app.
	     */
	    QString jsonAssetPath();

	    /**
	     * Sets the relative path to the JSON file containing the initial reminders list
	     * data.
	     *
	     * @param jsonAssetPath The new relative path to the JSON file residing in the assets folder.
	     */
	    void setJsonAssetPath(const QString jsonAssetPath);

	    /**
	     * Returns the filled status of the reminders list data. The application is set
	     * up so that the user only will be allowed to have one hundred items in total
	     * when the reminders is full false is returned.
	     *
	     * @return True if there is room for more items, otherwise false.
	     */
	    bool listIsFull();

	signals:


	 	/**
	     * Emitted when the filter changes.
	     *
	     * @param filter The new filter string.
	     */
	    void filterChanged(QString filter);

	    /**
	     * Emitted when the property holding the path to JSON file in the assets folder is changed.
	     *
	     * @param jsonAssetPath The new path to the JSON file in the asset path.
	     */
	    void jsonAssetPathChanged(QString jsonAssetPath);

	    /**
	     * Emitted when the reminders filled status is changed.
	     *
	     * @param myListIsFull true if the item limit of one hundred items is reached, otherwise false.
	     */
	    void myListIsChanged(bool myListIsFull);

	public slots:
	    /**
	     * Function that changes the status of a list of items.
	     *
	     * @param RemindersList The list of indexPaths to the item that should be changed.
	     * @param newCompletionStatus The new status that all items should have.
	     */
	    void setCompletionStatus(const QVariantList RemindersList, const QString newCompletionStatus);

	    /**
	     * Function that deletes an item
	     *
	     * @param item item to be deleted
	     */
	    void deleteListItem(const QVariant item);
	    /**
	     * Function that deletes the items at the index paths given in the parameter list.
	     *
	     * @param selectionList A list of indices to the items that should be removed.
	     */
	    void deleteListItems(const QVariantList RemindersList);

	    /**
	     * Function that adds a new item to the JSON file, the status will be set to "incomplete"
	     *
	     * @param itemIndex The string with the text describing the reminders title.
	     */
	    void addListItem(const QString itemText, const QString itemIndex);

	    /**
	     * Function that sets the completion status of an individual item
	     *
	     * @param item The item that is to be changed
	     * @param completionStatus the item's completion status
	     */

	    void setICompletionStatus (const QVariant item, const QString completionStatus);

	    /**
	     * Function that edits the content of an item.
	     *
	     * @param item The item that is to be edited.
	     * @param newitemText The item's text
	     * @param newItemIndex The new title text of the item.
	     */
	    void editListItem(const QVariant item, const QString newItemText, const QString newItemIndex);
	private:
	    /**
	     * In order to write to a file in a signed application the file has
	     * to reside in the apps data folder. This function copies the bundled
	     * JSON file to that folder.
	     *
	     * @return true either if the file is already or if the file was successfully copied, otherwise false.
	     */
	    bool jsonToDataFolder();

	    /**
	     * Helper function for saving the data in myRemindersData to the JSON file.
	     *
	     * @return If save was successful returns true.
	     */
	    bool saveData();

	    /**
	     * Helper function for evaluating if the reminders is full. Alters the remindersIsFull property
	     * if the state needs changing and emits the corresponding signal.
	     */
	    void checkIfListIsFull();

	    // Property variables.
	    QString myFilter;
	    QString myJsonAssetsPath;
	    QString myJsonDataPath;
	    bool myListIsFull;

	    // A list containing all data read from the JSON file.
	    QVariantList myRemindersData;

	    static const int maxItems = 500;

};
#endif /* APPMODEL_H_ */

