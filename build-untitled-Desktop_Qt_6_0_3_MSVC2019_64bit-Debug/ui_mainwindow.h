/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *dllbtn;
    QLabel *pathlabel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *scanbtn;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *modeCombobox;
    QPushButton *injectbtn;
    QProgressBar *progressBar;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuSETTINGS;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(565, 470);
        MainWindow->setMinimumSize(QSize(565, 470));
        MainWindow->setMaximumSize(QSize(565, 470));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 561, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dllbtn = new QPushButton(verticalLayoutWidget);
        dllbtn->setObjectName(QString::fromUtf8("dllbtn"));

        horizontalLayout_4->addWidget(dllbtn);

        pathlabel = new QLabel(verticalLayoutWidget);
        pathlabel->setObjectName(QString::fromUtf8("pathlabel"));

        horizontalLayout_4->addWidget(pathlabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scanbtn = new QPushButton(verticalLayoutWidget);
        scanbtn->setObjectName(QString::fromUtf8("scanbtn"));

        horizontalLayout_3->addWidget(scanbtn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 555, 297));
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_2->addWidget(scrollArea);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        modeCombobox = new QComboBox(verticalLayoutWidget);
        modeCombobox->setObjectName(QString::fromUtf8("modeCombobox"));

        horizontalLayout->addWidget(modeCombobox);

        injectbtn = new QPushButton(verticalLayoutWidget);
        injectbtn->setObjectName(QString::fromUtf8("injectbtn"));

        horizontalLayout->addWidget(injectbtn);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(7, 400, 551, 23));
        progressBar->setValue(24);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 565, 20));
        menuSETTINGS = new QMenu(menubar);
        menuSETTINGS->setObjectName(QString::fromUtf8("menuSETTINGS"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuSETTINGS->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        dllbtn->setText(QCoreApplication::translate("MainWindow", "Choose DLL", nullptr));
        pathlabel->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        scanbtn->setText(QCoreApplication::translate("MainWindow", "SCAN PROCESS", nullptr));
        injectbtn->setText(QCoreApplication::translate("MainWindow", "INJECT", nullptr));
        menuSETTINGS->setTitle(QCoreApplication::translate("MainWindow", "SETTINGS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
