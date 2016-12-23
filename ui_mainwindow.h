/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Log_start;
    QAction *action_Log_stop;
    QAction *action_exit;
    QAction *action_support;
    QAction *action_about;
    QAction *action_open;
    QAction *action_close;
    QAction *action_font;
    QAction *action_clear;
    QAction *action_Language;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_2;
    QComboBox *comboBox_5;
    QLabel *label;
    QComboBox *comboBox_6;
    QLabel *label_6;
    QComboBox *comboBox_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 583);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        action_Log_start = new QAction(MainWindow);
        action_Log_start->setObjectName(QStringLiteral("action_Log_start"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icon/work_log_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Log_start->setIcon(icon);
        action_Log_stop = new QAction(MainWindow);
        action_Log_stop->setObjectName(QStringLiteral("action_Log_stop"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_support = new QAction(MainWindow);
        action_support->setObjectName(QStringLiteral("action_support"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QStringLiteral("action_open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon1);
        action_close = new QAction(MainWindow);
        action_close->setObjectName(QStringLiteral("action_close"));
        action_font = new QAction(MainWindow);
        action_font->setObjectName(QStringLiteral("action_font"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icon/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_font->setIcon(icon2);
        action_clear = new QAction(MainWindow);
        action_clear->setObjectName(QStringLiteral("action_clear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_clear->setIcon(icon3);
        action_Language = new QAction(MainWindow);
        action_Language->setObjectName(QStringLiteral("action_Language"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icon/language.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Language->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(false);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout->addWidget(comboBox_4, 2, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout->addWidget(comboBox_5, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_6 = new QComboBox(groupBox);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        gridLayout->addWidget(comboBox_6, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBox_7 = new QComboBox(groupBox);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout->addWidget(comboBox_7, 5, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 1);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(true);

        gridLayout_3->addWidget(radioButton_3, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout_3->addWidget(radioButton_4, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 1, 3, 1, 1);

        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMaximum(100000000);
        spinBox->setValue(1000);

        gridLayout_3->addWidget(spinBox, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));

        verticalLayout_2->addWidget(plainTextEdit_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(pushButton, 0, Qt::AlignRight|Qt::AlignVCenter);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_Log_start);
        menu->addAction(action_exit);
        menu_2->addAction(action_support);
        menu_2->addAction(action_about);
        mainToolBar->addAction(action_open);
        mainToolBar->addAction(action_Log_start);
        mainToolBar->addAction(action_font);
        mainToolBar->addAction(action_Language);
        mainToolBar->addAction(action_clear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Log_start->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250Log", 0));
        action_Log_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242Log", 0));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        action_support->setText(QApplication::translate("MainWindow", "\350\265\236\345\212\251", 0));
        action_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        action_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\277\236\346\216\245", 0));
        action_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\350\277\236\346\216\245", 0));
        action_font->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223", 0));
#ifndef QT_NO_TOOLTIP
        action_font->setToolTip(QApplication::translate("MainWindow", "\345\255\227\344\275\223", 0));
#endif // QT_NO_TOOLTIP
        action_clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
        action_Language->setText(QApplication::translate("MainWindow", "language", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", 0));
        radioButton->setText(QApplication::translate("MainWindow", "ASCII", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "HEX", 0));
        checkBox->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\217\221\351\200\201", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\227\266\351\227\264", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "ASCII", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "HEX", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\345\217\221\351\200\201", 0));
        label_7->setText(QApplication::translate("MainWindow", "ms", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
