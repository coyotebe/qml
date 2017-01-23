#include "modelobject.h"

ModelObject::ModelObject(QQuickView *p) : QObject(NULL)
{
    m_pView = p;
}
