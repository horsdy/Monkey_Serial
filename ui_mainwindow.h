/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
    QAction *action_Log;
    QAction *action_exit;
    QAction *action_about;
    QAction *action_port;
    QAction *action_font;
    QAction *action_clear;
    QAction *action_Language;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionFind_Previous;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_databit;
    QComboBox *comboBox_port;
    QComboBox *comboBox_baud;
    QLabel *label_2;
    QComboBox *comboBox_checkbit;
    QLabel *label;
    QComboBox *comboBox_stopbit;
    QLabel *label_6;
    QComboBox *comboBox_flowctl;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_ascii;
    QRadioButton *radioButton_hex;
    QCheckBox *checkBox_newLine;
    QCheckBox *checkBox_showSend;
    QCheckBox *checkBox_showTime;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_ascii_send;
    QRadioButton *radioButton_hex_send;
    QPushButton *pushButton_retrans;
    QSpinBox *spinBox_retrans_int;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit_recv;
    QComboBox *comboBox_input_history;
    QPlainTextEdit *plainTextEdit_input;
    QPushButton *pushButton_send;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_help;
    QMenu *menu_tool;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(888, 582);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        action_Log = new QAction(MainWindow);
        action_Log->setObjectName(QStringLiteral("action_Log"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icon/work_log_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Log->setIcon(icon);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_port = new QAction(MainWindow);
        action_port->setObjectName(QStringLiteral("action_port"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/image/icon/stop.png"), QSize(), QIcon::Normal, QIcon::On);
        action_port->setIcon(icon1);
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
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/icon/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon5);
        actionFind_Next = new QAction(MainWindow);
        actionFind_Next->setObjectName(QStringLiteral("actionFind_Next"));
        actionFind_Previous = new QAction(MainWindow);
        actionFind_Previous->setObjectName(QStringLiteral("actionFind_Previous"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(false);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 3);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(220, 0));
        groupBox->setMaximumSize(QSize(220, 16777215));
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

        comboBox_databit = new QComboBox(groupBox);
        comboBox_databit->setObjectName(QStringLiteral("comboBox_databit"));

        gridLayout->addWidget(comboBox_databit, 2, 1, 1, 1);

        comboBox_port = new QComboBox(groupBox);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_port->sizePolicy().hasHeightForWidth());
        comboBox_port->setSizePolicy(sizePolicy1);
        comboBox_port->setMinimumSize(QSize(115, 0));
        comboBox_port->setMaximumSize(QSize(115, 16777215));

        gridLayout->addWidget(comboBox_port, 0, 1, 1, 1);

        comboBox_baud = new QComboBox(groupBox);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));

        gridLayout->addWidget(comboBox_baud, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_checkbit = new QComboBox(groupBox);
        comboBox_checkbit->setObjectName(QStringLiteral("comboBox_checkbit"));

        gridLayout->addWidget(comboBox_checkbit, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_stopbit = new QComboBox(groupBox);
        comboBox_stopbit->setObjectName(QStringLiteral("comboBox_stopbit"));

        gridLayout->addWidget(comboBox_stopbit, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBox_flowctl = new QComboBox(groupBox);
        comboBox_flowctl->setObjectName(QStringLiteral("comboBox_flowctl"));

        gridLayout->addWidget(comboBox_flowctl, 5, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(220, 0));
        groupBox_2->setMaximumSize(QSize(220, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_ascii = new QRadioButton(groupBox_2);
        radioButton_ascii->setObjectName(QStringLiteral("radioButton_ascii"));
        radioButton_ascii->setChecked(true);

        gridLayout_2->addWidget(radioButton_ascii, 0, 0, 1, 1);

        radioButton_hex = new QRadioButton(groupBox_2);
        radioButton_hex->setObjectName(QStringLiteral("radioButton_hex"));

        gridLayout_2->addWidget(radioButton_hex, 0, 1, 1, 1);

        checkBox_newLine = new QCheckBox(groupBox_2);
        checkBox_newLine->setObjectName(QStringLiteral("checkBox_newLine"));

        gridLayout_2->addWidget(checkBox_newLine, 1, 0, 1, 1);

        checkBox_showSend = new QCheckBox(groupBox_2);
        checkBox_showSend->setObjectName(QStringLiteral("checkBox_showSend"));

        gridLayout_2->addWidget(checkBox_showSend, 2, 0, 1, 1);

        checkBox_showTime = new QCheckBox(groupBox_2);
        checkBox_showTime->setObjectName(QStringLiteral("checkBox_showTime"));

        gridLayout_2->addWidget(checkBox_showTime, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(220, 0));
        groupBox_3->setMaximumSize(QSize(220, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        radioButton_ascii_send = new QRadioButton(groupBox_3);
        radioButton_ascii_send->setObjectName(QStringLiteral("radioButton_ascii_send"));
        radioButton_ascii_send->setChecked(true);

        gridLayout_3->addWidget(radioButton_ascii_send, 0, 0, 1, 1);

        radioButton_hex_send = new QRadioButton(groupBox_3);
        radioButton_hex_send->setObjectName(QStringLiteral("radioButton_hex_send"));

        gridLayout_3->addWidget(radioButton_hex_send, 0, 3, 1, 1);

        pushButton_retrans = new QPushButton(groupBox_3);
        pushButton_retrans->setObjectName(QStringLiteral("pushButton_retrans"));

        gridLayout_3->addWidget(pushButton_retrans, 1, 3, 1, 1);

        spinBox_retrans_int = new QSpinBox(groupBox_3);
        spinBox_retrans_int->setObjectName(QStringLiteral("spinBox_retrans_int"));
        sizePolicy.setHeightForWidth(spinBox_retrans_int->sizePolicy().hasHeightForWidth());
        spinBox_retrans_int->setSizePolicy(sizePolicy);
        spinBox_retrans_int->setMaximum(100000000);
        spinBox_retrans_int->setValue(1000);

        gridLayout_3->addWidget(spinBox_retrans_int, 1, 0, 1, 1);

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
        plainTextEdit_recv = new QPlainTextEdit(centralWidget);
        plainTextEdit_recv->setObjectName(QStringLiteral("plainTextEdit_recv"));
        plainTextEdit_recv->setMinimumSize(QSize(600, 349));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(12);
        plainTextEdit_recv->setFont(font1);
        plainTextEdit_recv->setContextMenuPolicy(Qt::DefaultContextMenu);
        plainTextEdit_recv->setStyleSheet(QLatin1String("selection-background-color: rgb(0, 170, 255);\n"
"selection-color: rgb(255, 255, 255);"));
        plainTextEdit_recv->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_recv->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        plainTextEdit_recv->setReadOnly(true);
        plainTextEdit_recv->setCenterOnScroll(false);

        verticalLayout_2->addWidget(plainTextEdit_recv);

        comboBox_input_history = new QComboBox(centralWidget);
        comboBox_input_history->setObjectName(QStringLiteral("comboBox_input_history"));
        comboBox_input_history->setFont(font1);

        verticalLayout_2->addWidget(comboBox_input_history);

        plainTextEdit_input = new QPlainTextEdit(centralWidget);
        plainTextEdit_input->setObjectName(QStringLiteral("plainTextEdit_input"));
        plainTextEdit_input->setFont(font1);
        plainTextEdit_input->setStyleSheet(QLatin1String("selection-background-color: rgb(0, 170, 255);\n"
"selection-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(plainTextEdit_input);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_send->sizePolicy().hasHeightForWidth());
        pushButton_send->setSizePolicy(sizePolicy2);
        pushButton_send->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(pushButton_send, 0, Qt::AlignRight|Qt::AlignVCenter);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 888, 23));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        menu_tool = new QMenu(menuBar);
        menu_tool->setObjectName(QStringLiteral("menu_tool"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_tool->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_file->addAction(action_port);
        menu_file->addAction(action_Log);
        menu_file->addAction(action_exit);
        menu_help->addAction(action_about);
        menu_tool->addAction(actionFind);
        menu_tool->addAction(actionFind_Next);
        menu_tool->addAction(actionFind_Previous);
        menu_tool->addAction(action_font);
        menu_tool->addAction(action_Language);
        mainToolBar->addAction(action_port);
        mainToolBar->addAction(action_Log);
        mainToolBar->addAction(action_font);
        mainToolBar->addAction(action_Language);
        mainToolBar->addAction(actionFind);
        mainToolBar->addAction(action_clear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Monkey Serial", Q_NULLPTR));
        action_Log->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\227\245\345\277\227", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_Log->setToolTip(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\227\245\345\277\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        action_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        action_port->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        action_font->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_font->setToolTip(QApplication::translate("MainWindow", "\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
        action_Language->setText(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_Language->setToolTip(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionFind->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionFind->setToolTip(QApplication::translate("MainWindow", "\346\237\245\346\211\276 (CTRL+F)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        actionFind_Next->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        actionFind_Next->setShortcut(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
        actionFind_Previous->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\344\270\212\344\270\200\344\270\252", Q_NULLPTR));
        actionFind_Previous->setShortcut(QApplication::translate("MainWindow", "Shift+F3", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\270\262   \345\217\243", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201   \346\216\247", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", Q_NULLPTR));
        radioButton_ascii->setText(QApplication::translate("MainWindow", "ASCII", Q_NULLPTR));
        radioButton_hex->setText(QApplication::translate("MainWindow", "HEX", Q_NULLPTR));
        checkBox_newLine->setText(QApplication::translate("MainWindow", "\346\215\242\350\241\214\346\230\276\347\244\272", Q_NULLPTR));
        checkBox_showSend->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_showTime->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\227\266\351\227\264", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", Q_NULLPTR));
        radioButton_ascii_send->setText(QApplication::translate("MainWindow", "ASCII", Q_NULLPTR));
        radioButton_hex_send->setText(QApplication::translate("MainWindow", "HEX", Q_NULLPTR));
        pushButton_retrans->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\345\217\221\351\200\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ms", Q_NULLPTR));
        comboBox_input_history->setCurrentText(QString());
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        menu_tool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
