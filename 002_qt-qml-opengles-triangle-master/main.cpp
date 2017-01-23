#include <QGuiApplication>
#include <QtQuick/QQuickView>

#include "gles-triangle-view.h"
#include "renderwidget.h"

int main(int argc, char *argv[])
{
    //QGuiApplication
    QApplication app(argc, argv);

	qmlRegisterType<Qoet::GLESTriangleView>("QOETDemo", 1, 0, "GLESTriangleView");

    qmlRegisterType<RenderWidget>("QOETDemo", 1, 0, "RenderWidget");

	QQuickView view;
	view.setResizeMode(QQuickView::SizeRootObjectToView);
	view.setSource(QUrl("qrc:///qml-ui/main.qml"));
	view.show();

	return app.exec();
}
