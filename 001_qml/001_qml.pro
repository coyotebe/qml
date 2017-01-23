QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    eventhandle.cpp \
    myclass.cpp \
    dataobject.cpp \
    modelobject.cpp \
    04_abstractlistmodel/animallistmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    eventhandle.h \
    myclass.h \
    dataobject.h \
    modelobject.h \
    04_abstractlistmodel/animallistmodel.h

FORMS +=
