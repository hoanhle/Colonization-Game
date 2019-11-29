QT += testlib
QT -= gui

TARGET = GameEventHandlerTest

CONFIG += c++14

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gameeventhandlertest.cpp \
            ../../Game/core/gameeventhandler.cpp \
            ../../Game/core/player.cpp \
            ../../Game/workers/newbasicworker.cpp \
            ../../Course/CourseLib/core/playerbase.cpp \
            ../../Course/CourseLib/core/basicresources.cpp \
            ../../Course/CourseLib/tiles/tilebase.cpp \
            ../../Course/CourseLib/core/gameobject.cpp \
            ../../Course/CourseLib/core/placeablegameobject.cpp \
            ../../Course/CourseLib/core/coordinate.cpp \
            ../../Course/CourseLib/workers/workerbase.cpp \



DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Game/core/gameeventhandler.hh \
    ../../Course/CourseLib/core/resourcemaps.h \

INCLUDEPATH += \
    ../../Course/CourseLib/ \
    ../../Game/
