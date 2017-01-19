#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    enum FONT_TYPE_ENUM {
        FONT_CONSOLAS,
        FONT_COURIER_NEW,
        FONT_SONG,
        FONT_MS_YAHEI,

        FONT_MAX
    };

    enum LANG_TYPE_ENUM {
        MY_LANG_CHINESE,
        MY_LANG_ENGLISH,

        MY_LANG_MAX
    };

    QStringList *font_list = NULL;

    void update_show(uint, uint, uint);

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

signals:
    void settings_change(uint, uint, uint);

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
