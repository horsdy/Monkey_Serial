#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTGUI>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include "qextserial/qextserialport.h"
#include <QFileDialog>
#include <QSplitter>
#include <QTSQL>

#include "find.h"
#include "ui_find.h"
#include "settings.h"
#include "ui_settings.h"
#include "about.h"
#include "ui_about.h"

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
    void readIniFile();
    void fillPortsInfo();
    void fillPortsParameters();
    void initSignalSlot();
    void appendContent(const QString &showBuf, bool isRecv = true);
    void closeEvent(QCloseEvent *event);


private slots:
    void on_action_port_triggered();

    void on_action_Log_triggered();

    void on_action_Language_triggered();

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

    void on_comboBox_input_history_activated(const QString &arg1);

    void on_comboBox_baud_currentTextChanged(const QString &arg1);

    void on_comboBox_databit_currentTextChanged(const QString &arg1);

    void on_comboBox_checkbit_currentTextChanged(const QString &arg1);

    void on_comboBox_stopbit_currentTextChanged(const QString &arg1);

    void on_comboBox_flowctl_currentTextChanged(const QString &arg1);

    void on_checkBox_showSend_stateChanged(int arg1);

    void on_radioButton_ascii_send_toggled(bool checked);

    void on_radioButton_hex_send_toggled(bool checked);

    void on_spinBox_retrans_int_valueChanged(const QString &arg1);

    void on_comboBox_baud_currentIndexChanged(int index);

    void on_actionFind_triggered();

    void on_find_str(QString &str, uint flags);

    void on_actionFind_Next_triggered();

    void on_actionFind_Previous_triggered();

    void on_action_font_triggered();

    void on_settings_change(uint font, uint size, uint lang);

    void on_action_about_triggered();

private:
    Ui::MainWindow *ui;
    QextSerialPort *serial;
    QStringList portList;
    QTimer *retransTimer;
    QString logfile_path;
    QString home_dir;
    QFile *logFile;
    QLabel *connLabel;
    QLabel *RXLabel;
    QLabel *TXLabel;
    QSqlDatabase db;
    Find *find = NULL;
    QString myFindStr;
    Settings *setting = NULL;
    About *about = NULL;

    bool isSerialConnected = false;
    bool isLoging = false;       //read from setting file
    bool isShowTime = false;     //read from setting file
    bool isShowSendData = false; //read from setting file
    bool isChinese = true;       //read from setting file
    bool isRetransing = false;
    bool init_ok_flag = false;
    bool is_case_sensitive = false;

    int rxBytesTotal = 0;
    int txBytesTotal = 0;
};

#endif // MAINWINDOW_H
