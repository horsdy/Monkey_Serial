#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTGUI>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include "qextserial/qextserialport.h"
#include <QFileDialog>

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
    void appendContent(const QString &showBuf, bool isRecv = true);

private slots:
    void on_action_port_triggered();

    void on_action_Log_triggered();

    void on_action_Language_triggered();

    void customBaud(int);
    void readData();

    void on_action_clear_triggered();

    void on_pushButton_send_clicked();

    void on_checkBox_showTime_stateChanged(int arg1);

    void on_checkBox_newLine_stateChanged(int arg1);

    void on_radioButton_ascii_toggled(bool checked);

    void on_radioButton_hex_toggled(bool checked);

    void on_pushButton_retrans_clicked();
    void on_retrans();

    void on_action_exit_triggered();

private:
    Ui::MainWindow *ui;
    QextSerialPort *serial;
    QStringList portList;
    QTimer *retransTimer;
    QString logfile_path;

    bool isSerialConnected = false;
    bool isLoging = false;       //read from setting file
    bool isShowTime = false;     //read from setting file
    bool isShowSendData = false; //read from setting file
    bool isChinese = true;       //read from setting file
    bool isRetransing = false;
};

#endif // MAINWINDOW_H
