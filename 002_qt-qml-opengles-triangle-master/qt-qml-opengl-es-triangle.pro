QT += qml quick opengl

SOURCES += \
	main.cpp \
	gles-triangle-renderer.cpp \
	gles-triangle-view.cpp \
    renderwidget.cpp

RESOURCES += \
	qoet-rc.qrc

HEADERS += \
	gles-triangle-renderer.h \
	gles-triangle-view.h \
        renderwidget.h
LIBS += -lopengl32 -lglu32
