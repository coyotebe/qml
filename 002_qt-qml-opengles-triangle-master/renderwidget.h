#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtOpenGL>
#include <QtGui>

class RenderWidget: public QGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    RenderWidget();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // RENDERWIDGET_H
