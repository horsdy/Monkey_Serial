/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Find
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QRadioButton *radioButton_previous;
    QRadioButton *radioButton_next;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Find)
    {
        if (Find->objectName().isEmpty())
            Find->setObjectName(QStringLiteral("Find"));
        Find->resize(397, 99);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Find->setFont(font);
        Find->setModal(false);
        verticalLayout = new QVBoxLayout(Find);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Find);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Find);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Find);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(Find);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        radioButton_previous = new QRadioButton(Find);
        radioButton_previous->setObjectName(QStringLiteral("radioButton_previous"));

        horizontalLayout_2->addWidget(radioButton_previous);

        radioButton_next = new QRadioButton(Find);
        radioButton_next->setObjectName(QStringLiteral("radioButton_next"));
        radioButton_next->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_next);

        pushButton_2 = new QPushButton(Find);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Find);

        QMetaObject::connectSlotsByName(Find);
    } // setupUi

    void retranslateUi(QDialog *Find)
    {
        Find->setWindowTitle(QApplication::translate("Find", "Find", Q_NULLPTR));
        label->setText(QApplication::translate("Find", "\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Find", "\346\237\245\346\211\276", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Find", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        radioButton_previous->setText(QApplication::translate("Find", "\346\237\245\346\211\276\345\211\215\344\270\200\344\270\252", Q_NULLPTR));
        radioButton_next->setText(QApplication::translate("Find", "\346\237\245\346\211\276\345\220\216\344\270\200\344\270\252", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Find", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Find: public Ui_Find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
