#ifndef FIND_H
#define FIND_H

#include <QDialog>

namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);
    ~Find();

public:
    void insert(QString &text);
    void clear();
    void update_show(uint font, uint size, uint lang);

signals:
    void find_str(QString &str, uint flag);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Find *ui;
};

#endif // FIND_H
