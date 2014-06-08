#include "app.h"
#include "AppModel.h"

#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

using namespace bb::cascades;

App::App()
{
	//registers the model for populating the reminders list, so that it can be accessed from the QML directly
	qmlRegisterType<AppModel>("com.app.appmodel",1,0,"AppModel");
	//qmlRegisterType<QDateTime>("custom.lib", 1, 0, "QDateTime");

    QmlDocument *qml = QmlDocument::create("asset:///main.qml");
    qml->setContextProperty("invokable", this);
    //ensures qml is loaded without errors
    if (!qml->hasErrors()) {

    	AbstractPane *root = qml->createRootObject<AbstractPane>();

    	if (root) {

    	    Application::instance()->setScene(root);

    	}

    }
}
