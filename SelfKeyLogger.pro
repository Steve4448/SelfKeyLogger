#-------------------------------------------------
#
# Project created by QtCreator 2012-12-16T19:33:06
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = SelfKeyLogger
TEMPLATE = app


SOURCES += main.cpp\
		keyloggerwindow.cpp \
	keyboardlistener.cpp

HEADERS  += keyloggerwindow.h \
	keyboardlistener.h \
    main.h

FORMS    += keyloggerwindow.ui
