/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUser;
    QLineEdit *lineEditUser;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelFullName;
    QLineEdit *lineEditFullName;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelAge;
    QLineEdit *lineEditAge;
    QLabel *labelGender;
    QComboBox *comboBoxGender;
    QPushButton *btnSignUp;

    void setupUi(QWidget *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName("SignUpForm");
        SignUpForm->resize(371, 379);
        verticalLayout = new QVBoxLayout(SignUpForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUser = new QLabel(SignUpForm);
        labelUser->setObjectName("labelUser");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUser);

        lineEditUser = new QLineEdit(SignUpForm);
        lineEditUser->setObjectName("lineEditUser");
        lineEditUser->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 89, 89);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUser);

        labelPassword = new QLabel(SignUpForm);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(SignUpForm);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(243, 255, 108);"));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);

        labelFullName = new QLabel(SignUpForm);
        labelFullName->setObjectName("labelFullName");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelFullName);

        lineEditFullName = new QLineEdit(SignUpForm);
        lineEditFullName->setObjectName("lineEditFullName");
        lineEditFullName->setStyleSheet(QString::fromUtf8("border-color:rgb(139, 255, 172)"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditFullName);

        labelEmail = new QLabel(SignUpForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(SignUpForm);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setStyleSheet(QString::fromUtf8("border-color:rgb(170, 85, 127)"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditEmail);

        labelAge = new QLabel(SignUpForm);
        labelAge->setObjectName("labelAge");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelAge);

        lineEditAge = new QLineEdit(SignUpForm);
        lineEditAge->setObjectName("lineEditAge");
        lineEditAge->setStyleSheet(QString::fromUtf8("border-color: rgb(65, 255, 242);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditAge);

        labelGender = new QLabel(SignUpForm);
        labelGender->setObjectName("labelGender");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelGender);

        comboBoxGender = new QComboBox(SignUpForm);
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->setObjectName("comboBoxGender");

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxGender);


        verticalLayout->addLayout(formLayout);

        btnSignUp = new QPushButton(SignUpForm);
        btnSignUp->setObjectName("btnSignUp");

        verticalLayout->addWidget(btnSignUp);


        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QWidget *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Sign Up", nullptr));
        labelUser->setText(QCoreApplication::translate("SignUpForm", "user name:", nullptr));
        labelPassword->setText(QCoreApplication::translate("SignUpForm", "password:", nullptr));
        labelFullName->setText(QCoreApplication::translate("SignUpForm", "full name: ", nullptr));
        labelEmail->setText(QCoreApplication::translate("SignUpForm", "email:", nullptr));
        labelAge->setText(QCoreApplication::translate("SignUpForm", "age:", nullptr));
        labelGender->setText(QCoreApplication::translate("SignUpForm", "gender: ", nullptr));
        comboBoxGender->setItemText(0, QCoreApplication::translate("SignUpForm", "male", nullptr));
        comboBoxGender->setItemText(1, QCoreApplication::translate("SignUpForm", "female", nullptr));

        comboBoxGender->setCurrentText(QCoreApplication::translate("SignUpForm", "male", nullptr));
        btnSignUp->setText(QCoreApplication::translate("SignUpForm", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
