#include <QTextDocument>

#include "find.h"
#include "ui_find.h"
#include "settings.h"
#include <QTranslator>
#include <qDebug>

Find::Find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = this->windowFlags();
    flags = flags & (~Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(flags);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
}

Find::~Find()
{
    delete ui;
}

void Find::on_pushButton_2_clicked()
{
    this->close();
}

void Find::clear()
{
    this->ui->lineEdit->clear();
}

void Find::insert(QString &text)
{
    this->ui->lineEdit->insert(text);
}

void Find::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    uint flags = 0;

    if (ui->checkBox->isChecked())
        flags |= QTextDocument::FindCaseSensitively;

    if (ui->radioButton_previous->isChecked())
        flags |= QTextDocument::FindBackward;

    //send to MainWindow to find
    emit find_str(str, flags);
}

void Find::update_show(uint font, uint size, uint lang)
{
    //set language
    QTranslator translator;
    QString lang_path("");

    qDebug()<< "Find lang" << lang;

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
}



