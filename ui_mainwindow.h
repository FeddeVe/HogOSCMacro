/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *Connection;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton_7;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QCheckBox *checkBox_5;
    QLabel *label_7;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_8;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QPushButton *pushButton_6;
    QCheckBox *checkBox;
    QLabel *label_11;
    QProgressBar *progressBar;
    QLabel *label_15;
    QCheckBox *checkBox_6;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_9;
    QLabel *label_6;
    QLabel *label_14;
    QCheckBox *checkBox_7;
    QPushButton *pushButton_5;
    QCheckBox *checkBox_4;
    QLabel *label_12;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QWidget *tab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout->addWidget(listWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        Connection = new QWidget();
        Connection->setObjectName("Connection");
        gridLayout = new QGridLayout(Connection);
        gridLayout->setObjectName("gridLayout");
        lineEdit_2 = new QLineEdit(Connection);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 6, 2, 1, 1);

        pushButton = new QPushButton(Connection);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        lineEdit = new QLineEdit(Connection);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        label_3 = new QLabel(Connection);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(Connection);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(Connection);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 4, 2, 1, 1);

        label_2 = new QLabel(Connection);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(Connection);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximum(9999);
        spinBox->setValue(7004);

        gridLayout->addWidget(spinBox, 1, 2, 1, 1);

        spinBox_2 = new QSpinBox(Connection);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMaximum(9999);
        spinBox_2->setValue(7123);

        gridLayout->addWidget(spinBox_2, 2, 2, 1, 1);

        label = new QLabel(Connection);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(Connection);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(Connection);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 5, 2, 1, 1);

        tabWidget->addTab(Connection, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 14, 1, 1, 1);

        checkBox_5 = new QCheckBox(tab_2);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setChecked(true);

        gridLayout_2->addWidget(checkBox_5, 2, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 10, 1, 1, 1);

        checkBox_3 = new QCheckBox(tab_2);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setChecked(true);

        gridLayout_2->addWidget(checkBox_3, 1, 1, 1, 1);

        checkBox_8 = new QCheckBox(tab_2);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setChecked(true);

        gridLayout_2->addWidget(checkBox_8, 4, 0, 1, 1);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 11, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_2->addWidget(pushButton_3, 6, 0, 1, 2);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 13, 0, 1, 1);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout_2->addWidget(pushButton_6, 9, 0, 1, 1);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName("checkBox");
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 13, 1, 1, 1);

        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName("progressBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 16, 0, 1, 2);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");

        gridLayout_2->addWidget(label_15, 15, 1, 1, 1);

        checkBox_6 = new QCheckBox(tab_2);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setChecked(true);

        gridLayout_2->addWidget(checkBox_6, 3, 0, 1, 1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 11, 0, 1, 1);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout_2->addWidget(pushButton_4, 7, 0, 1, 2);

        checkBox_2 = new QCheckBox(tab_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setChecked(true);

        gridLayout_2->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox_9 = new QCheckBox(tab_2);
        checkBox_9->setObjectName("checkBox_9");
        checkBox_9->setChecked(true);

        gridLayout_2->addWidget(checkBox_9, 4, 1, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 10, 0, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");

        gridLayout_2->addWidget(label_14, 15, 0, 1, 1);

        checkBox_7 = new QCheckBox(tab_2);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setChecked(true);

        gridLayout_2->addWidget(checkBox_7, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout_2->addWidget(pushButton_5, 8, 0, 1, 2);

        checkBox_4 = new QCheckBox(tab_2);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setChecked(true);

        gridLayout_2->addWidget(checkBox_4, 2, 0, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 14, 0, 1, 1);

        checkBox_10 = new QCheckBox(tab_2);
        checkBox_10->setObjectName("checkBox_10");
        checkBox_10->setChecked(true);

        gridLayout_2->addWidget(checkBox_10, 5, 0, 1, 1);

        checkBox_11 = new QCheckBox(tab_2);
        checkBox_11->setObjectName("checkBox_11");
        checkBox_11->setChecked(true);

        gridLayout_2->addWidget(checkBox_11, 5, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "192.168.178.192", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Test Master:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CommandLine", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Test Connection", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Desk Port:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Desk IP:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "My Port:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Check A B", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Connection), QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Page 4", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Page 2", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "Page 7", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Create Pages", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "KeyPresses Left:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Create First Page", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Page Default", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Page 5", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Total Number off KeyPresses:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Create Bumps", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Page 1", nullptr));
        checkBox_9->setText(QCoreApplication::translate("MainWindow", "Page 8", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "StartTime:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Time Left:", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Page 6", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Create Default Page", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Page 3", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Avg KeyPress Time:", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", "Page 9", nullptr));
        checkBox_11->setText(QCoreApplication::translate("MainWindow", "Page 10", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Page Creation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
