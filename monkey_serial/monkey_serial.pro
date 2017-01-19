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


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserial/qextserialport.cpp \
    qextserial/qextserialport_win.cpp \
    find.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    qextserial/qextserialport.h \
    qextserial/qextserialport_global.h \
    qextserial/qextserialport_p.h \
    find.h \
    settings.h

FORMS    += mainwindow.ui \
    find.ui \
    settings.ui

RESOURCES += \
    monkey.qrc

DISTFILES += \
    qextserial/LICENSE \
    style/fontawesome-webfont.ttf \
    style/qt_zh_CN.qm \
    style/add-line_horizontal.png \
    style/add-line_vertical.png \
    style/array_down.png \
    style/checkbox_checked.png \
    style/checkbox_unchecked.png \
    style/error.png \
    style/Font Awesome Cheatsheet.png \
    style/info.png \
    style/question.png \
    style/radio_normal.png \
    style/radio_selected.png \
    style/sub-line_horizontal.png \
    style/sub-line_vertical.png \
    style/blue.css \
    style/gray.css \
    style/navy.css
