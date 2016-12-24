#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_port_triggered();

    void on_action_Log_triggered();

    void on_action_Language_triggered();

private:
    Ui::MainWindow *ui;
    bool isSerialConnected = false;
    bool isLoging = false;       //read from setting file
    bool isShowTime = false;     //read from setting file
    bool isShowSendData = false; //read from setting file
    bool isChinese = true;       //read from setting file
};

#endif // MAINWINDOW_H
