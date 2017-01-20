#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QTranslator translator;

    if (translator.load(QString(":/resource/resource/main_widget_en.qm")) )
        a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
