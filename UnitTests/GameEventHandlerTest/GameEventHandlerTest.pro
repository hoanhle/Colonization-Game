QT += testlib
QT -= gui

TARGET = GameEventHandlerTest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gameeventhandlertest.cpp \
            ../../Game/core/gameeventhandler.cpp \
            ../../Game/core/player.cpp \
            ../../Course/CourseLib/Core/playerbase.cpp \
            ../../Course/CourseLib/Core/basicresources.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Game/core/gameeventhandler.hh \
    ../..Course/CourseLib/Core/resourcemaps.hh

INCLUDEPATH += \
    ../../Course/CourseLib/ \
    ../../Game/
