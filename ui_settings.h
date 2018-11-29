/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_font;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QComboBox *comboBox_fontsize;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBox_lang;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->setWindowModality(Qt::ApplicationModal);
        Settings->resize(338, 120);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Settings->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Settings);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(Settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(67, 0));

        horizontalLayout_3->addWidget(label_4);

        comboBox_font = new QComboBox(Settings);
        comboBox_font->setObjectName(QStringLiteral("comboBox_font"));
        comboBox_font->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(comboBox_font);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_5 = new QLabel(Settings);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        comboBox_fontsize = new QComboBox(Settings);
        comboBox_fontsize->setObjectName(QStringLiteral("comboBox_fontsize"));

        horizontalLayout_3->addWidget(comboBox_fontsize);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        comboBox_lang = new QComboBox(Settings);
        comboBox_lang->setObjectName(QStringLiteral("comboBox_lang"));
        comboBox_lang->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(comboBox_lang);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        buttonBox_2 = new QDialogButtonBox(Settings);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Setting", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "\345\255\227\344\275\223\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "\345\255\227\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Settings", "Language : ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
