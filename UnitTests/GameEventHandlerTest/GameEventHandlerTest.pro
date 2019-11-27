QT += testlib
QT -= gui

TARGET = GameEventHandlerTest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gameeventhandlertest.cpp \
            ../../Game/core/gameeventhandler.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Game/core/gameeventhandler.hh

INCLUDEPATH += \
    ../../Course/CourseLib/ \
    ../../Game/
