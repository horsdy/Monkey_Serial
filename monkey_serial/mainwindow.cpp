#include <QtDebug>
#include <QtSerialPort>
#include <QSettings>
#include <QAbstractScrollArea>
#include <QFontComboBox>
#include <qnamespace.h>
#include <QTextDocument>
#include <QRect>
#include <QDesktopWidget>
#include <QWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "ui_settings.h"

#define RED_TEXT_STYLESHEET   "color: rgb(170, 0, 0);font: 10pt \"微软雅黑\";"
#define GREEN_TEXT_STYLESHEET "color: rgb(0, 85, 0); font: 10pt \"微软雅黑\";"
#define INPUT_MAX 20

#define FONT_STYLE "font: %1pt \"%2\";"
#define DEFAULT_COLOR_PLAINTEXT "selection-background-color: rgb(0, 170, 255);selection-color: rgb(255, 255, 255);"

#define INIT_FILE_PATH "./serial_setting.ini"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QextSerialPort( );
    retransTimer = new QTimer(this);
    logFile = new QFile(this);
    connLabel = new QLabel(" Disconnected", this);
    RXLabel = new QLabel("RX : 0 Bytes", this);
    TXLabel = new QLabel("TX : 0 Bytes", this);
    QLabel *voidLabel = new QLabel(this);
    ui->comboBox_input_history->setMaxCount(INPUT_MAX);

    //window icon
    setWindowIcon(QIcon(":/image/icon/serial-port.png"));
    //status bar
    connLabel->setStyleSheet(RED_TEXT_STYLESHEET);
    ui->statusBar->addWidget(connLabel, 1);
    ui->statusBar->addWidget(RXLabel, 1);
    ui->statusBar->addWidget(TXLabel, 1);
    ui->statusBar->addWidget(voidLabel, 3);

    //Spliter
    QSplitter *pSpliter = new QSplitter(Qt::Vertical, this);
    QVBoxLayout *pVboxLayoutRight = new QVBoxLayout(this);
    QWidget *rightButtomWidget = new QWidget(this);

    ui->horizontalLayout_2->removeItem(ui->verticalLayout_2);
    pVboxLayoutRight->addWidget(ui->comboBox_input_history);
    pVboxLayoutRight->addWidget(ui->plainTextEdit_input);
    pVboxLayoutRight->addWidget(ui->pushButton_send);
    pVboxLayoutRight->setContentsMargins(0,0,0,0);
    pVboxLayoutRight->setAlignment(ui->pushButton_send, Qt::AlignRight);
    rightButtomWidget->setLayout(pVboxLayoutRight);

    pSpliter->addWidget(ui->plainTextEdit_recv);
    pSpliter->addWidget(rightButtomWidget);

    //top 4:1 buttom
    pSpliter->setStretchFactor(0, 4);
    pSpliter->setStretchFactor(1, 1);

    ui->horizontalLayout_2->addWidget(pSpliter);

    //init tool bar

    fillPortsInfo();
    //read port setting file
    fillPortsParameters();
    readIniFile();
    initSignalSlot();

    //init db
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost"); //设置数据库主机名
    db.setDatabaseName("InputHistory.db"); //设置数据库名
    if (db.open())
    {
        qDebug() << "Database open OK";
        //read input history
        QSqlQuery sqlQuery;
        sqlQuery.prepare("select data from input");
        if (sqlQuery.exec())
        {
            qDebug() << "select DB OK.";
            while(sqlQuery.next())
            {
                QString str = sqlQuery.value(0).toString();
                ui->comboBox_input_history->insertItem(0, str);
                ui->comboBox_input_history->setCurrentText(str);
            }
        }
        else
            qDebug() << "select DB Fail: " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Database open Fail: " << db.lastError();
    }

    init_ok_flag = true;
    qDebug() << "Init OK";
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
    delete serial;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //write position size to file
    int x = this->geometry().x();
    int y = this->geometry().y();
    int width = this->geometry().width();
    int height = this->geometry().height();

    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);
    if (file)
    {
        file->setValue("/UI/X", x);
        file->setValue("/UI/Y", y);
        file->setValue("/UI/Width", width);
        file->setValue("/UI/Height", height);

        if (windowState() & Qt::WindowMaximized)
            file->setValue("UI/WindowMax", 1);
        else
            file->setValue("UI/WindowMax", 0);
    }

    QMainWindow::closeEvent(event);
}

//Read setting file about port, show
void MainWindow::readIniFile()
{
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file)
        return;

    QString BaudRate = file->value("/PortSetting/BaudRate").toString();
    QString DataBit = file->value("/PortSetting/DataBit").toString();
    QString ParityBit = file->value("/PortSetting/ParityBit").toString();
    QString StopBit = file->value("/PortSetting/StopBit").toString();
    QString FlowCtrl = file->value("/PortSetting/FlowCtrl").toString();
    QString RecvCode = file->value("/RecvSetting/RecvCode").toString();
    bool ShownInNewline = file->value("/RecvSetting/ShownInNewline").toBool();
    bool ShowSend = file->value("/RecvSetting/ShowSend").toBool();
    bool ShowTime = file->value("/RecvSetting/ShowTime").toBool();
    QString SendCode = file->value("/SendSetting/SendCode").toString();
    int Interval = file->value("/ResendSetting/Interval").toInt();
    QString font = file->value("/UI/Font").toString();
    QString size = file->value("/UI/FontSize").toString();
    int lang = file->value("/UI/Lang").toInt();
    int x = file->value("/UI/X").toInt();
    int y = file->value("/UI/Y").toInt();
    int width = file->value("/UI/Width").toInt();
    int height = file->value("/UI/Height").toInt();
    int is_max = file->value("/UI/WindowMax").toInt();

    ui->comboBox_baud->setCurrentText(BaudRate);
    ui->comboBox_databit->setCurrentText(DataBit);
    ui->comboBox_checkbit->setCurrentText(ParityBit);
    ui->comboBox_stopbit->setCurrentText(StopBit);
    ui->comboBox_flowctl->setCurrentText(FlowCtrl);

    if (RecvCode.compare("ASCII", Qt::CaseInsensitive) == 0)
        ui->radioButton_ascii->setChecked(true);
    else
        ui->radioButton_hex->setChecked(true);

    ui->checkBox_newLine->setChecked(ShownInNewline);
    ui->checkBox_showSend->setChecked(ShowSend);
    ui->checkBox_showTime->setChecked(ShowTime);

    if (SendCode.compare("ASCII", Qt::CaseInsensitive) == 0)
        ui->radioButton_ascii_send->setChecked(true);
    else
        ui->radioButton_hex_send->setChecked(true);

    ui->spinBox_retrans_int->setValue(Interval);

    //set font of plaintext
    ui->plainTextEdit_recv->setStyleSheet(QString(FONT_STYLE).arg(size).arg(font) + DEFAULT_COLOR_PLAINTEXT);
    ui->plainTextEdit_input->setStyleSheet(QString(FONT_STYLE).arg(size).arg(font) + DEFAULT_COLOR_PLAINTEXT);

    //set language
    QTranslator translator;
    QString lang_path("");
    if (lang == Settings::MY_LANG_CHINESE)
    {
        lang_path = ":/resource/resource/main_widget_zh.qm";
    }
    else if (lang == Settings::MY_LANG_ENGLISH)
    {
        lang_path = ":/resource/resource/main_widget_en.qm";
    }

    if (translator.load(lang_path) )
    {
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
    }

    if (is_max)
    {
        Qt::WindowStates state = windowState();
        state |= Qt::WindowMaximized;
        setWindowState(state);
    }
    else if (width > 0 && height > 0)
    {
        //move to last position
        move(x, y);
        resize(width, height);
    }
    else
    {
        //move to certal
        QDesktopWidget *desktop = QApplication::desktop();
        int width = desktop->availableGeometry(this).width();
        int height = desktop->availableGeometry(this).height();

        move((width - this->width())/2, (height - this->height())/2);
    }
    delete file;
}

void MainWindow::initSignalSlot()
{
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(retransTimer, SIGNAL(timeout()), this, SLOT(on_retrans()) );
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
    ui->comboBox_checkbit->addItem(tr("Even"), PAR_EVEN);
    ui->comboBox_checkbit->addItem(tr("Odd"), PAR_ODD);
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

void MainWindow::appendContent(const QString &showBuf, bool isRecv)
{
    QString myShowBuf;

    if (false == isSerialConnected)
        return;

    if (ui->checkBox_showTime->isChecked())
    {
        if (isRecv)
        {
            myShowBuf = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz @R] ");
        }
        else
        {
            myShowBuf = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz @T] ");
        }
    }

    myShowBuf += showBuf;
    if (ui->checkBox_newLine->isChecked())
    {
        //show in the new line
        ui->plainTextEdit_recv->appendPlainText(myShowBuf);
    }
    else
    {
        ui->plainTextEdit_recv->moveCursor(QTextCursor::End);
        ui->plainTextEdit_recv->insertPlainText(myShowBuf);
        ui->plainTextEdit_recv->moveCursor(QTextCursor::End);
        ui->plainTextEdit_recv->centerCursor();
    }

    //write to log file
    if (isLoging)
    {
        if (ui->checkBox_newLine->isChecked())
        {
            myShowBuf.append("\r\n");
        }
        logFile->write(myShowBuf.toLatin1().data(), myShowBuf.size());
    }
}

void MainWindow::on_action_port_triggered()
{
    if (!this->isSerialConnected)
    {
        QString port = portList.at(ui->comboBox_port->currentIndex());
        BaudRateType baud = static_cast<BaudRateType>(ui->comboBox_baud->currentText().toInt());
        DataBitsType dataBits = static_cast<DataBitsType>(
                    ui->comboBox_databit->itemData(ui->comboBox_databit->currentIndex()).toInt());
        ParityType parity = static_cast<ParityType>(
                    ui->comboBox_checkbit->itemData(ui->comboBox_checkbit->currentIndex()).toInt());
        StopBitsType stopBits = static_cast<StopBitsType>(
                    ui->comboBox_stopbit->itemData(ui->comboBox_stopbit->currentIndex()).toInt());
        FlowType flowControl = static_cast<FlowType>(
                    ui->comboBox_flowctl->itemData(ui->comboBox_flowctl->currentIndex()).toInt());

        if (baud == 0)
        {
            QMessageBox::critical(this, tr("Error"), "Baud rate can't be 0");
            return;
        }

        if ( port.isEmpty() )
        {
            QMessageBox::critical(this, tr("Error"), "Port can't be NULL");
            return;
        }

        serial->setPortName( port );
        serial->setBaudRate( baud);
        serial->setDataBits(dataBits);
        serial->setParity(parity);
        serial->setStopBits(stopBits);
        serial->setFlowControl(flowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            //open ok
            this->isSerialConnected = true;
            ui->action_port->setIcon(QIcon(":/image/icon/stop.png"));
            ui->action_port->setToolTip(tr("断开连接"));
            ui->groupBox->setEnabled(false);
            connLabel->setStyleSheet(GREEN_TEXT_STYLESHEET);
            connLabel->setText(" Connected");
        } else {
            this->isSerialConnected = false;
            ui->action_port->setIcon(QIcon(":/image/icon/play.png"));
            ui->action_port->setToolTip(tr("打开连接"));

            ui->groupBox->setEnabled(true);
            isRetransing = false;
            retransTimer->stop();

            ui->action_Log->setIcon(QIcon(":/image/icon/work_log_on.png"));
            ui->action_Log->setToolTip(tr("启动日志") );
            connLabel->setStyleSheet(RED_TEXT_STYLESHEET);
            connLabel->setText(" Disconnected");
            logfile_path.clear();
            //Close File
            logFile->close();
            serial->close();
            isLoging = false;

            QMessageBox::critical(this, tr("Error"), serial->errorString());
        }
    }
    else
    {
        this->isSerialConnected = false;
        ui->action_port->setIcon(QIcon(":/image/icon/play.png"));
        ui->action_port->setToolTip(tr("打开连接") );

        ui->groupBox->setEnabled(true);
        isRetransing = false;
        retransTimer->stop();

        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_on.png"));
        ui->action_Log->setToolTip(tr("启动日志") );
        connLabel->setStyleSheet(RED_TEXT_STYLESHEET);
        connLabel->setText(" Disconnected");
        logfile_path.clear();
        //Close File
        logFile->close();

        serial->close();
    }
}

void MainWindow::on_action_Log_triggered()
{
    this->isLoging = !this->isLoging;

    if (this->isLoging)
    {
        //若没有设置log文件路径，则弹窗让用户选择文件夹
        if (logfile_path.isEmpty())
        {
            logfile_path = QFileDialog::getExistingDirectory(this,"Log File Path","./");
        }

        if(logfile_path.isEmpty())
        {
            this->isLoging = false;
        }
        else
        {
            QString filename;

            ui->action_Log->setIcon(QIcon(":/image/icon/work_log_off.png"));
            ui->action_Log->setToolTip(tr("停止日志") );
            filename = QDateTime::currentDateTime().toString("Log_yyyyMMdd_hhmmss");
            filename.append(".txt");
            QDir::setCurrent(logfile_path);
            logFile->setFileName(filename);
            logFile->open(QIODevice::WriteOnly);
        }
    }
    else
    {
        ui->action_Log->setIcon(QIcon(":/image/icon/work_log_on.png"));
        ui->action_Log->setToolTip(tr("启动日志"));
        logfile_path.clear();
        //Close File
        logFile->close();
    }
}

void MainWindow::on_action_Language_triggered()
{
    on_action_font_triggered();
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    QString showBuf;
    QString asciiBuf = QString(data);
    QString hexstr;

    if (ui->radioButton_ascii->isChecked())
    {
        showBuf = asciiBuf;
    }
    else if (ui->radioButton_hex->isChecked())
    {
        int i = 0;

        for (i = 0; i < data.size(); i++)
        {
            hexstr += QString("%1 ").arg(data.at(i), 2, 16);
        }
        showBuf = hexstr;
    }

    appendContent(showBuf);

    //update status bar
    rxBytesTotal += data.size();
    RXLabel->setText("RX : " + QString::number(rxBytesTotal) + " Bytes");
}

void MainWindow::on_action_clear_triggered()
{
    ui->plainTextEdit_recv->clear();
    rxBytesTotal = 0;
    txBytesTotal = 0;
    RXLabel->setText("RX : 0 Bytes");
    TXLabel->setText("TX : 0 Bytes");
}

void MainWindow::on_pushButton_send_clicked()
{
    if (isSerialConnected)
    {
        QByteArray data = ui->plainTextEdit_input->toPlainText().toLatin1();
        QByteArray mydata;

        if (ui->radioButton_ascii_send->isChecked())
        {
            mydata = data;
        }
        else if (ui->radioButton_hex_send->isChecked())
        {
            int i = 0;
            //remove all non-hex char
            for (i = 0; i < data.size(); )
            {
                if (data.at(i) >= '0' && data.at(i) <= '9' ||
                    data.at(i) >= 'a' && data.at(i) <= 'f' ||
                    data.at(i) >= 'A' && data.at(i) <= 'F' )
                {
                    i++;
                }
                else
                {
                    data.remove(i, 1);
                }
            }
            mydata = QByteArray::fromHex(data);
        }

        serial->write(mydata);

        //update status bar
        txBytesTotal += mydata.size();
        TXLabel->setText("TX : " + QString::number(txBytesTotal)  + " Bytes");

        //show send content
        if (ui->checkBox_showSend->isChecked())
        {
            //insert space into hex data
            if (ui->radioButton_hex_send->isChecked() )
            {
                QString str;
                int i = 0;

                for (i = 0; i < mydata.size(); i++)
                {
                    str += QString("%1 ").arg(mydata.at(i), 2, 16);
                }
                appendContent(str, false);
            }
            else
            {
                appendContent(QString(mydata), false);
            }
        }

        //write to combobox
        int idx;
        for (idx = 0; idx < ui->comboBox_input_history->count(); idx++)
        {
            if (data == ui->comboBox_input_history->itemText(idx))
            {
                break;
            }
        }

        //new input data
        if (idx >= ui->comboBox_input_history->count())
        {
            //write to database
            QSqlQuery sqlQuery;
            if (ui->comboBox_input_history->count() >= INPUT_MAX)
            {
                //delete first record
                sqlQuery.prepare("delete from input where data = (SELECT data from input LIMIT 0,1)");
                if (sqlQuery.exec())
                    qDebug() << "delete DB OK.";
                else
                    qDebug() << "delete DB Fail: " << sqlQuery.lastError();
            }

            sqlQuery.prepare("insert into input values(?)");
            sqlQuery.addBindValue(data);
            if (sqlQuery.exec())
                qDebug() << "insert DB OK.";
            else
                qDebug() << "insert DB Fail: " << sqlQuery.lastError();

            ui->comboBox_input_history->insertItem(0, QString(data));
            ui->comboBox_input_history->setCurrentText(QString(data));
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Serial Port Not Connected."));
    }
}

void MainWindow::on_retrans()
{
    on_pushButton_send_clicked();
    retransTimer->start(ui->spinBox_retrans_int->value());
}

void MainWindow::on_checkBox_showTime_stateChanged(int arg1)
{
    if (Qt::Checked == arg1)
    {
        ui->checkBox_newLine->setChecked(true);
        ui->checkBox_newLine->setEnabled(false);
    }
    else if (Qt::Unchecked == arg1)
    {
        ui->checkBox_newLine->setChecked(false);
        ui->checkBox_newLine->setEnabled(true);
    }

    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file || FALSE == init_ok_flag)
        return;

    if (Qt::Checked == arg1)
        file->setValue("/RecvSetting/ShowTime", "TRUE");
    else
        file->setValue("/RecvSetting/ShowTime", "FALSE");

    delete file;
}

void MainWindow::on_checkBox_newLine_stateChanged(int arg1)
{
    if (isSerialConnected && Qt::Unchecked == arg1)
    {
        ui->plainTextEdit_recv->appendPlainText(""); //turn to new line
    }
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (Qt::Checked == arg1)
        file->setValue("/RecvSetting/ShownInNewline", "TRUE");
    else
        file->setValue("/RecvSetting/ShownInNewline", "FALSE");

    delete file;
}

void MainWindow::on_radioButton_ascii_toggled(bool checked)
{
    if (isSerialConnected && checked)
        ui->plainTextEdit_recv->appendPlainText(""); //turn to new line

    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (checked)
        file->setValue("/RecvSetting/RecvCode", "ASCII");

    delete file;
}

void MainWindow::on_radioButton_hex_toggled(bool checked)
{
    if (isSerialConnected && checked)
    {
        ui->plainTextEdit_recv->appendPlainText(""); //turn to new line
    }
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (checked)
        file->setValue("/RecvSetting/RecvCode", "HEX");

    delete file;
}

void MainWindow::on_pushButton_retrans_clicked()
{
    if (!isSerialConnected)
    {
        QMessageBox::critical(this, tr("Error"), tr("Serial Port Not Connected."));
        return;
    }
    if (ui->plainTextEdit_input->document()->toPlainText().isEmpty())
    {
        QMessageBox::critical(this, tr("Error"), tr("Send Content Is Empty."));
        return;
    }
    if (ui->spinBox_retrans_int->value() == 0)
    {
        QMessageBox::critical(this, tr("Error"), tr("Zero Resend Interval."));
        return;
    }

    isRetransing = !isRetransing;
    if (isRetransing)
    {
        retransTimer->setInterval(ui->spinBox_retrans_int->value());
        retransTimer->setSingleShot(false);
        retransTimer->start();
        ui->pushButton_retrans->setText(tr("停止"));
    }
    else
    {
        retransTimer->stop();
        ui->pushButton_retrans->setText(tr("重复发送") );
    }
}

void MainWindow::on_action_exit_triggered()
{
    close();
}

void MainWindow::on_comboBox_input_history_activated(const QString &arg1)
{
    ui->plainTextEdit_input->clear();
    ui->plainTextEdit_input->appendPlainText(arg1);
}

void MainWindow::on_comboBox_baud_currentTextChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/PortSetting/BaudRate", arg1);

    delete file;
}

void MainWindow::on_comboBox_databit_currentTextChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/PortSetting/DataBit", arg1);

    delete file;
}

void MainWindow::on_comboBox_checkbit_currentTextChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/PortSetting/ParityBit", arg1);

    delete file;
}

void MainWindow::on_comboBox_stopbit_currentTextChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/PortSetting/StopBit", arg1);

    delete file;
}

void MainWindow::on_comboBox_flowctl_currentTextChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/PortSetting/FlowCtrl", arg1);

    delete file;
}

void MainWindow::on_checkBox_showSend_stateChanged(int arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (Qt::Checked == arg1)
        file->setValue("/RecvSetting/ShowSend", "TRUE");
    else
        file->setValue("/RecvSetting/ShowSend", "FALSE");

    delete file;
}

void MainWindow::on_radioButton_ascii_send_toggled(bool checked)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (checked)
        file->setValue("/SendSetting/SendCode", "ASCII");

    delete file;
}

void MainWindow::on_radioButton_hex_send_toggled(bool checked)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    if (checked)
        file->setValue("/SendSetting/SendCode", "HEX");

    delete file;
}

void MainWindow::on_spinBox_retrans_int_valueChanged(const QString &arg1)
{
    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

   file->setValue("/ResendSetting/Interval", arg1);

    delete file;
}

void MainWindow::on_comboBox_baud_currentIndexChanged(int index)
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

void MainWindow::on_actionFind_triggered()
{
    if (find)
    {
        find->clear();
        QString text = this->ui->plainTextEdit_recv->textCursor().selectedText();
        find->insert(text);

        find->show();
        find->raise();
        find->activateWindow();
    }
    else
    {
        find = new Find(this);
        connect(find, SIGNAL(find_str(QString&,uint)), this, SLOT(on_find_str(QString&,uint)) );

        find->setWindowTitle("Find");
        find->clear();
        QString text = this->ui->plainTextEdit_recv->textCursor().selectedText();
        find->insert(text);
        find->show();
    }
}

void MainWindow::on_find_str(QString &str, uint flags)
{
    QTextDocument::FindFlags options = (QTextDocument::FindFlags) flags;
    ui->plainTextEdit_recv->find(str, options);
    myFindStr = str;
    if ( (options & QTextDocument::FindCaseSensitively) != 0)
    {
        is_case_sensitive = true;
    }
    else
    {
        is_case_sensitive = false;
    }
}

void MainWindow::on_actionFind_Next_triggered()
{
    if (find == NULL || myFindStr.isEmpty())
        return;

    QTextDocument::FindFlags flags = 0;
    if (is_case_sensitive)
        flags = QTextDocument::FindCaseSensitively;

    //find next
    ui->plainTextEdit_recv->find(myFindStr, flags);
}

void MainWindow::on_actionFind_Previous_triggered()
{
    if (find == NULL || myFindStr.isEmpty())
        return;

    QTextDocument::FindFlags flags = 0;
    if (is_case_sensitive)
        flags = QTextDocument::FindCaseSensitively;

    //find previous
    flags |= QTextDocument::FindBackward;
    ui->plainTextEdit_recv->find(myFindStr, flags);
}

void MainWindow::on_action_font_triggered()
{
    if (setting)
    {
        QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

        if (NULL == file)
            return;

        QString font = file->value("/UI/Font").toString();
        int size = file->value("/UI/FontSize").toInt();
        int lang = file->value("/UI/Lang").toInt();
        int font_idx = setting->font_list->indexOf(font);

        setting->update_show(font_idx, size, lang);
        setting->show();
        setting->raise();
        setting->activateWindow();
    }
    else
    {
        setting = new Settings(this);
        connect(setting, SIGNAL(settings_change(uint, uint, uint)),
                this, SLOT(on_settings_change(uint, uint, uint)));

        QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

        if (NULL == file)
            return;

        QString font = file->value("/UI/Font").toString();
        int size = file->value("/UI/FontSize").toInt();
        int lang = file->value("/UI/Lang").toInt();
        int font_idx = setting->font_list->indexOf(font);

        setting->update_show(font_idx, size, lang);
        setting->show();
    }
}

void MainWindow::on_settings_change(uint font, uint size, uint lang)
{
    //set font of receiving text and sending text
    QString fontstr = setting->font_list->at(font);

    ui->plainTextEdit_recv->setStyleSheet(QString(FONT_STYLE).arg(size).arg(fontstr) + DEFAULT_COLOR_PLAINTEXT);
    ui->plainTextEdit_input->setStyleSheet(QString(FONT_STYLE).arg(size).arg(fontstr) + DEFAULT_COLOR_PLAINTEXT);

    //set language
    QTranslator translator;
    QString lang_path("");
    if (lang == Settings::MY_LANG_CHINESE)
    {
        lang_path = ":/resource/resource/main_widget_zh.qm";
    }
    else if (lang == Settings::MY_LANG_ENGLISH)
    {
        lang_path = ":/resource/resource/main_widget_en.qm";
    }

    if (translator.load(lang_path) )
    {
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        this->update();
    }

    //write to .ini file
    QSettings *file = new QSettings(INIT_FILE_PATH, QSettings::IniFormat);

    if (NULL == file|| FALSE == init_ok_flag)
        return;

    file->setValue("/UI/Font", fontstr);
    file->setValue("/UI/FontSize", size);
    file->setValue("/UI/Lang", lang);

    delete file;
}

void MainWindow::on_action_about_triggered()
{
   if (about)
   {
       about->show();
       about->raise();
       about->activateWindow();
   }
   else
   {
       about = new About(this);
       about->show();
   }
}
