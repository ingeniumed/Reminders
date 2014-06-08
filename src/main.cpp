#include "app.h"
#include "ActiveFrame.h"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <QLocale>
#include <QTranslator>

#define QT_DECLARATIVE_DEBUG
#include <Qt/qdeclarativedebug.h>

using ::bb::cascades::Application;

int main(int argc, char **argv)
{

    //-- this is where the server is started etc
    Application app(argc, argv);

    //-- localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "Reminders_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }
    
    app.setCover(new ActiveFrame());

    App mainApp;
    
    //-- we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    //-- when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}
