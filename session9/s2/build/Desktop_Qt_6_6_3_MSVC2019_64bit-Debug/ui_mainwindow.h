/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnLogin;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSignUp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(593, 571);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(81, 76, 79);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(58, 23, 255);\n"
"color: rgb(255, 23, 38);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(152, 255, 120);"));

        verticalLayout->addWidget(btnLogin);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnSignUp = new QPushButton(centralwidget);
        btnSignUp->setObjectName("btnSignUp");
        btnSignUp->setStyleSheet(QString::fromUtf8("background-color: rgb(93, 131, 255)"));

        verticalLayout->addWidget(btnSignUp);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Main Window", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sign In   Sign Up", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        btnSignUp->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
