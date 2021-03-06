#ifndef ACTIVEFRAME_H_
#define ACTIVEFRAME_H_

#include <bb/cascades/SceneCover>
#include <bb/cascades/Container>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Label>

using namespace ::bb::cascades;

class ActiveFrame: public SceneCover {
	Q_OBJECT

public:
	ActiveFrame();
	virtual ~ActiveFrame();

public slots:
	void update();

private:
	Container *mMainContainer;
	QmlDocument *qml;

};

#endif /* ACTIVEFRAME_H_ */
