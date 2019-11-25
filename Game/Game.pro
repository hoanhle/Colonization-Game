TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    buildings/apartmentblock.cpp \
    graphics/assigndialog.cpp \
    workers/farmer.cpp \
    core/gameeventhandler.cpp \
    core/gamescene.cpp \
    graphics/highscoredialog.cpp \
    buildings/housingbase.cpp \
    buildings/largehouse.cpp \
    workers/logger.cpp \
    main.cpp \
    graphics/mapitem.cpp \
    graphics/mapwindow.cc \
    buildings/mine.cpp \
    workers/miner.cpp \
    workers/newbasicworker.cpp \
    core/objectmanager.cpp \
    rock.cpp \
    graphics/rulesdialog.cpp \
    sand.cpp \
    buildings/sawmill.cpp \
    graphics/setplayerdialog.cpp \
    buildings/skyscraper.cpp \
    buildings/smallhouse.cpp \
    graphics/startdialog.cpp \
    graphics/unassigndialog.cpp \
    water.cpp

HEADERS += \
    buildings/apartmentblock.hh \
    graphics/assigndialog.hh \
    workers/farmer.hh \
    core/gameeventhandler.hh \
    core/gamescene.hh \
    graphics/highscoredialog.hh \
    buildings/housingbase.hh \
    buildings/largehouse.hh \
    workers/logger.hh \
    graphics/mapitem.hh \
    graphics/mapwindow.hh \
    buildings/mine.hh \
    workers/miner.hh \
    workers/newbasicworker.hh \
    core/nresourcemaps.hh \
    core/objectmanager.hh \
    rock.hh \
    graphics/rulesdialog.hh \
    sand.hh \
    buildings/sawmill.hh \
    graphics/setplayerdialog.hh \
    buildings/skyscraper.hh \
    buildings/smallhouse.hh \
    graphics/startdialog.hh \
    graphics/unassigndialog.hh \
    water.hh

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    graphics/assigndialog.ui \
    graphics/highscoredialog.ui \
    graphics/mapwindow.ui \
    graphics/rulesdialog.ui \
    graphics/setplayerdialog.ui \
    graphics/startdialog.ui \
    graphics/unassigndialog.ui

RESOURCES += \
    Icons.qrc

DISTFILES +=
