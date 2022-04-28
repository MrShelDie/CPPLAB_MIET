/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "coloredqtextbrowser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLine;
    QPushButton *searchButton;
    QPushButton *fileSearchButton;
    ColoredQTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_3;
    QLabel *id_label;
    QLineEdit *id_input;
    QLabel *name_label;
    QLineEdit *name_input;
    QLabel *year_label;
    QLineEdit *year_input;
    QLabel *sex_label;
    QComboBox *sex_input;
    QPushButton *add_employee_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchLine = new QLineEdit(centralwidget);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));

        horizontalLayout->addWidget(searchLine);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout->addWidget(searchButton);

        fileSearchButton = new QPushButton(centralwidget);
        fileSearchButton->setObjectName(QString::fromUtf8("fileSearchButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileSearchButton->sizePolicy().hasHeightForWidth());
        fileSearchButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(fileSearchButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new ColoredQTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        id_label = new QLabel(centralwidget);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        horizontalLayout_3->addWidget(id_label);

        id_input = new QLineEdit(centralwidget);
        id_input->setObjectName(QString::fromUtf8("id_input"));

        horizontalLayout_3->addWidget(id_input);

        name_label = new QLabel(centralwidget);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout_3->addWidget(name_label);

        name_input = new QLineEdit(centralwidget);
        name_input->setObjectName(QString::fromUtf8("name_input"));

        horizontalLayout_3->addWidget(name_input);

        year_label = new QLabel(centralwidget);
        year_label->setObjectName(QString::fromUtf8("year_label"));

        horizontalLayout_3->addWidget(year_label);

        year_input = new QLineEdit(centralwidget);
        year_input->setObjectName(QString::fromUtf8("year_input"));

        horizontalLayout_3->addWidget(year_input);

        sex_label = new QLabel(centralwidget);
        sex_label->setObjectName(QString::fromUtf8("sex_label"));

        horizontalLayout_3->addWidget(sex_label);

        sex_input = new QComboBox(centralwidget);
        sex_input->addItem(QString());
        sex_input->addItem(QString());
        sex_input->setObjectName(QString::fromUtf8("sex_input"));

        horizontalLayout_3->addWidget(sex_input);

        add_employee_btn = new QPushButton(centralwidget);
        add_employee_btn->setObjectName(QString::fromUtf8("add_employee_btn"));

        horizontalLayout_3->addWidget(add_employee_btn);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(searchButton, SIGNAL(clicked()), MainWindow, SLOT(sFindEmployee()));
        QObject::connect(add_employee_btn, SIGNAL(clicked()), MainWindow, SLOT(sAddEmployee()));
        QObject::connect(searchButton, SIGNAL(clicked()), searchLine, SLOT(clear()));
        QObject::connect(add_employee_btn, SIGNAL(clicked()), id_input, SLOT(clear()));
        QObject::connect(add_employee_btn, SIGNAL(clicked()), name_input, SLOT(clear()));
        QObject::connect(add_employee_btn, SIGNAL(clicked()), year_input, SLOT(clear()));
        QObject::connect(fileSearchButton, SIGNAL(clicked()), MainWindow, SLOT(sSearchFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchLine->setInputMask(QString());
        searchLine->setText(QString());
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        fileSearchButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        id_label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        name_label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236:", nullptr));
        year_label->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        sex_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273:", nullptr));
        sex_input->setItemText(0, QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271", nullptr));
        sex_input->setItemText(1, QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271", nullptr));

        add_employee_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
