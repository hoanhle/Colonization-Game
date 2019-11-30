QT += testlib
QT -= gui

TARGET = ObjectManagerTest

CONFIG += c++14

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_objectmanagertest.cpp \
        ../../Game/core/gameeventhandler.cpp \
        ../../Game/core/objectmanager.cpp \
        ../../Game/core/player.cpp \
        ../../Game/workers/newbasicworker.cpp \
        ../../Course/CourseLib/core/playerbase.cpp \
        ../../Course/CourseLib/core/coordinate.cpp \
        ../../Course/CourseLib/core/gameobject.cpp \
        ../../Course/CourseLib/tiles/tilebase.cpp \
        ../../Course/CourseLib/tiles/grassland.cpp \
        ../../Course/CourseLib/buildings/buildingbase.cpp \
        ../../Course/CourseLib/workers/workerbase.cpp \
        ../../Course/CourseLib/core/placeablegameobject.cpp \
        ../../Course/CourseLib/core/basicresources.cpp \




HEADERS += \
        ../../Game/core/objectmanager.hh \
        ../../Game/core/gameeventhandler.hh \
        ../../Course/CourseLib/core/coordinate.h \
        ../../Course/CourseLib/tiles/tilebase.h \
        ../../Course/CourseLib/core/basicresources.h \

INCLUDEPATH += \
    ../../Course/CourseLib/ \
    ../../Game/
