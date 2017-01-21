#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T17:24:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += serialport
TARGET = monkey_serial
TEMPLATE = app

RC_FILE = res.rc
TRANSLATIONS += resource/main_widget_zh.ts  \
                resource/main_widget_en.ts

SOURCES += main.cpp\
        mainwindow.cpp \
    qextserial/qextserialport.cpp \
    qextserial/qextserialport_win.cpp \
    find.cpp \
    settings.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    qextserial/qextserialport.h \
    qextserial/qextserialport_global.h \
    qextserial/qextserialport_p.h \
    find.h \
    settings.h \
    about.h

FORMS    += mainwindow.ui \
    find.ui \
    settings.ui \
    about.ui

RESOURCES += \
    monkey.qrc

DISTFILES += \
    qextserial/LICENSE
