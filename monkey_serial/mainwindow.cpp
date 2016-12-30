#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QtSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QextSerialPort( );
    fillPortsInfo();
    fillPortsParameters();
    initSignalSlot();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serial;
}

void MainWindow::fillPortsInfo()
{
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        QString item = info.portName() + " ("+ info.description() + ")";
        portList.append(info.portName());
        ui->comboBox_port->addItem(item);
    }
}

void MainWindow::fillPortsParameters()
{
    //baud
    ui->comboBox_baud->addItem("9600");
    ui->comboBox_baud->addItem("19200");
    ui->comboBox_baud->addItem("38400");
    ui->comboBox_baud->addItem("57600");
    ui->comboBox_baud->addItem("115200");
    ui->comboBox_baud->addItem("230400");
    ui->comboBox_baud->addItem("460800");
    ui->comboBox_baud->addItem("921600");
    ui->comboBox_baud->addItem(tr("Custom"));

    //data bit
    ui->comboBox_databit->addItem(QStringLiteral("5"), DATA_5);
    ui->comboBox_databit->addItem(QStringLiteral("6"), DATA_6);
    ui->comboBox_databit->addItem(QStringLiteral("7"), DATA_7);
    ui->comboBox_databit->addItem(QStringLiteral("8"), DATA_8);
    ui->comboBox_databit->setCurrentIndex(3);

    //parity
    ui->comboBox_checkbit->addItem(tr("None"), PAR_NONE);
    ui->comboBox_checkbit->addItem(tr("Even"), PAR_ODD);
    ui->comboBox_checkbit->addItem(tr("Odd"), PAR_EVEN);
#if defined(Q_OS_WIN) || defined(qdoc)
    ui->comboBox_checkbit->addItem(tr("Mark"), PAR_MARK);
#endif
    ui->comboBox_checkbit->addItem(tr("Space"), PAR_SPACE);

    ui->comboBox_stopbit->addItem(QStringLiteral("1"), STOP_1);
#ifdef Q_OS_WIN
    ui->comboBox_stopbit->addItem(tr("1.5"), STOP_1_5);
#endif
    ui->comboBox_stopbit->addItem(QStringLiteral("2"), STOP_2);

    ui->comboBox_flowctl->addItem(tr("None"), FLOW_OFF);
    ui->comboBox_flowctl->addItem(tr("RTS/CTS"), FLOW_HARDWARE);
    ui->comboBox_flowctl->addItem(tr("XON/XOFF"), FLOW_XONXOFF);
}

void MainWindow::on_action_port_triggered()
{
    this->isSerialConnected = !this->isSerialConnected;

    if (this->isSerialConnected)
    {
        ui->action_port->setIcon(QIcon(":/image/icon/stop.png"));
        ui->action_port->setToolTip("断开连接");

        BaudRateType baud = static_cast<BaudRateType>(ui->comboBox_baud->currentText().toInt());
        DataBitsType dataBits = static_cast<DataBitsType>(
                    ui->comboBox_databit->itemData(ui->comboBox_databit->currentIndex()).toInt());
        ParityType parity = static_cast<ParityType>(
                    ui->comboBox_checkbit->itemData(ui->comboBox_checkbit->currentIndex()).toInt());
        StopBitsType stopBits = static_cast<StopBitsType>(
                    ui->comboBox_stopbit->itemData(ui->comboBox_stopbit->currentIndex()).toInt());
        FlowType flowControl = static_cast<FlowType>(
                    ui->comboBox_flowctl->itemData(ui->comboBox_flowctl->currentIndex()).toInt());

        serial->setPortName( portList.at(ui->comboBox_port->currentIndex()) );
        serial->setBaudRate( baud);
        serial->setDataBits(dataBits);
        serial->setParity(parity);
        serial->setStopBits(stopBits);
        serial->setFlowControl(flowControl);
        if (serial->open(QIODevice::ReadWrite)) {
            //open ok
            ui->groupBox->setEnabled(false);
        } else {
            QMessageBox::critical(this, tr("Error"), serial->errorString());
        }
    }
    else
    {
        ui->action_port->setIcon(QIcon(":/image/icon/play.png"));
        ui->action_port->setToolTip("连接");

        ui->groupBox->setEnabled(true);
        serial->close();
    }
}

void MainWindow::on_action_Log_triggered()
{
    this->isLoging = !this->isLoging;

    if (this->isLoging)
    {
        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_off.png"));
        ui->action_Log->setToolTip("停止日志");

        //Close File
    }
    else
    {
        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_on.png"));
        ui->action_Log->setToolTip("启动日志");
        //若没有设置log文件路径，则弹窗让用户选择文件夹

    }
}

void MainWindow::on_action_Language_triggered()
{
    this->isChinese = !this->isChinese;

    if (this->isChinese)
    {
        ui->action_Language->setIcon(QIcon(":/image/icon/english.png"));
        ui->action_Language->setToolTip("Switch to English");
    }
    else
    {
        ui->action_Language->setIcon(QIcon(":/image/icon/chinese.png"));
        ui->action_Language->setToolTip("切换到中文");
    }
}


void MainWindow::customBaud(int index)
{
    if (8 == index)
    {
        ui->comboBox_baud->setEditable(true);
        ui->comboBox_baud->clearEditText();
    }
    else
    {
        ui->comboBox_baud->setEditable(false);
    }
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    QString buf = QString(data);

    ui->plainTextEdit_recv->setPlainText( ui->plainTextEdit_recv->document()->toPlainText() + buf );
}

void MainWindow::on_action_clear_triggered()
{
    ui->plainTextEdit_recv->clear();
}

void MainWindow::on_pushButton_send_clicked()
{
    if (isSerialConnected)
    {
        QByteArray data = ui->plainTextEdit_input->toPlainText().toLatin1();
        serial->write(data);
    }
}






/* add function above this */
void MainWindow::initSignalSlot()
{
    connect(ui->comboBox_baud, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::customBaud);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}
