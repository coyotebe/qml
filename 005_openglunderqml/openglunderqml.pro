QT += qml quick opengl

HEADERS += squircle.h
SOURCES += squircle.cpp main.cpp
RESOURCES += openglunderqml.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/openglunderqml
INSTALLS += target

LIBS += -lopengl32 -lglu32

