#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include "qextserial/qextserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void fillPortsInfo();
    void fillPortsParameters();
    void initSignalSlot();

private slots:
    void on_action_port_triggered();

    void on_action_Log_triggered();

    void on_action_Language_triggered();

    void customBaud(int);
    void readData();

    void on_action_clear_triggered();

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *serial;
    QStringList portList;

    bool isSerialConnected = false;
    bool isLoging = false;       //read from setting file
    bool isShowTime = false;     //read from setting file
    bool isShowSendData = false; //read from setting file
    bool isChinese = true;       //read from setting file
};

#endif // MAINWINDOW_H
