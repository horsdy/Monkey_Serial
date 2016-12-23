#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_port_triggered()
{
    this->isSerialConnected = !this->isSerialConnected;

    if (this->isSerialConnected)
    {
        ui->action_port->setIcon(QIcon(":/image/icon/stop.png"));
        ui->action_port->setToolTip("断开连接");
    }
    else
    {
        ui->action_port->setIcon(QIcon(":/image/icon/play.png"));
        ui->action_port->setToolTip("连接");
    }
}

void MainWindow::on_action_Log_triggered()
{
    this->isLoging = !this->isLoging;

    if (this->isLoging)
    {
        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_on.png"));
        ui->action_Log->setToolTip("正在记录日志...");
    }
    else
    {
        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_off.png"));
        ui->action_Log->setToolTip("未启动日志");
    }
}
