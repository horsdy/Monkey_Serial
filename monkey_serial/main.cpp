#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QTranslator translator;

    if (translator.load(QString(":/resource/resource/main_widget_en.qm")) )
        a.installTranslator(&translator);


    w.show();
    return a.exec();
}
