/********************************************************************************
** Form generated from reading UI file 'signinform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINFORM_H
#define UI_SIGNINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUser;
    QLineEdit *lineEditUser;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *btnLogin;

    void setupUi(QWidget *SignInForm)
    {
        if (SignInForm->objectName().isEmpty())
            SignInForm->setObjectName("SignInForm");
        SignInForm->resize(249, 223);
        verticalLayout = new QVBoxLayout(SignInForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUser = new QLabel(SignInForm);
        labelUser->setObjectName("labelUser");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUser);

        lineEditUser = new QLineEdit(SignInForm);
        lineEditUser->setObjectName("lineEditUser");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUser);

        labelPassword = new QLabel(SignInForm);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(SignInForm);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);


        verticalLayout->addLayout(formLayout);

        btnLogin = new QPushButton(SignInForm);
        btnLogin->setObjectName("btnLogin");

        verticalLayout->addWidget(btnLogin);


        retranslateUi(SignInForm);

        QMetaObject::connectSlotsByName(SignInForm);
    } // setupUi

    void retranslateUi(QWidget *SignInForm)
    {
        SignInForm->setWindowTitle(QCoreApplication::translate("SignInForm", "Sign In", nullptr));
        labelUser->setText(QCoreApplication::translate("SignInForm", "User Name:", nullptr));
        labelPassword->setText(QCoreApplication::translate("SignInForm", "Password:", nullptr));
        btnLogin->setText(QCoreApplication::translate("SignInForm", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInForm: public Ui_SignInForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINFORM_H
