#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = this->windowFlags();
    flags = flags & (~Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(flags);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    font_list = new QStringList();
    *font_list << "Consolas" << "Courier New" << "宋体" << "微软雅黑";
    ui->comboBox_font->addItems(*font_list);

    QStringList sizeList;
    sizeList << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "14" << "16" << "18"
             << "20" << "22" << "24" << "26" << "28" << "36" << "48" << "72";
    ui->comboBox_fontsize->addItems(sizeList);

    QStringList langList;
    langList << "中文" << "English";
    ui->comboBox_lang->addItems(langList);
}

Settings::~Settings()
{
    delete ui;
    delete font_list;
}

void Settings::on_buttonBox_2_accepted()
{
    uint font = 0, size = 0, lang = 0;
    font = ui->comboBox_font->currentIndex();
    size = ui->comboBox_fontsize->currentText().toInt();
    lang = ui->comboBox_lang->currentIndex();

    emit settings_change(font, size, lang);
    this->close();
}

void Settings::on_buttonBox_2_rejected()
{
    this->close();
}

void Settings::update_show(uint font, uint size, uint lang)
{
    ui->comboBox_font->setCurrentIndex(font);
    ui->comboBox_fontsize->setCurrentText(QString::number(size) );
    ui->comboBox_lang->setCurrentIndex(lang);
}


