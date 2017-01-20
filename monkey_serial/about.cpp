#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = this->windowFlags();
    flags = flags & (~Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(flags);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    this->close();
}
