QT += testlib
QT -= gui

TARGET = GameEventHandlerTest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gameeventhandlertest.cpp \
            ../../Game/core/gameeventhandler.cpp \
            ../../Game/core/player.cpp \
            ../../Course/CourseLib/core/playerbase.cpp \
            ../../Course/CourseLib/core/basicresources.cpp \


DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Game/core/gameeventhandler.hh \
    ../../Course/CourseLib/core/resourcemaps.h

INCLUDEPATH += \
    ../../Course/CourseLib/ \
    ../../Game/
