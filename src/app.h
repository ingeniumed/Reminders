#ifndef APP_H
#define APP_H

#include <bb/cascades/Application>

/*
 * a reminders app designed to make your life easy by allowing
 * you to create multiple tasks with unique descriptions and due
 * dates attached so as to not forget them. They can be classified
 * as to be done, incomplete or complete.
 */

class App : public QObject
{
    Q_OBJECT

public:
    App();
};

#endif // ifndef APP_H
