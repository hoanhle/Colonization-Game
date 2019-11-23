TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    assigndialog.cpp \
    gameeventhandler.cpp \
    gamescene.cpp \
    highscoredialog.cpp \
    housingbase.cpp \
    main.cpp \
    mapitem.cpp \
    mapwindow.cc \
    objectmanager.cpp \
    rock.cpp \
    rulesdialog.cpp \
    sand.cpp \
    setplayerdialog.cpp \
    smallhouse.cpp \
    startdialog.cpp \
    unassigndialog.cpp \
    water.cpp

HEADERS += \
    assigndialog.hh \
    gameeventhandler.hh \
    gamescene.hh \
    highscoredialog.hh \
    housingbase.hh \
    mapitem.hh \
    mapwindow.hh \
    nresourcemaps.hh \
    objectmanager.hh \
    rock.hh \
    rulesdialog.hh \
    sand.hh \
    setplayerdialog.hh \
    smallhouse.hh \
    startdialog.hh \
    unassigndialog.hh \
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
    assigndialog.ui \
    highscoredialog.ui \
    mapwindow.ui \
    rulesdialog.ui \
    setplayerdialog.ui \
    startdialog.ui \
    unassigndialog.ui

RESOURCES += \
    Icons.qrc

DISTFILES +=
