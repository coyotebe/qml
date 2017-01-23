#include "renderwidget.h"
RenderWidget::RenderWidget()
    : QGLWidget()
{
}

void RenderWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void RenderWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth(1.0f);
    glColor3d(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(-1.0, +0.0);
    glVertex2d(+1.0, +0.0);
    glVertex2d(+0.0, -1.0);
    glVertex2d(+0.0, +1.0);
    glEnd();
}
