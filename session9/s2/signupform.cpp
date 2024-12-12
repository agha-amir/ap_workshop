#include "signupform.h"
#include "ui_signupform.h"
#include <fstream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRegularExpression>
#include <QHash>
#include <sstream>
using namespace std;

SignUpForm::SignUpForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpForm)
{
    ui->setupUi(this);

    connect(ui->btnSignUp, &QPushButton::clicked, this, &SignUpForm::signUp);
}

SignUpForm::~SignUpForm()
{
    delete ui;
}

void SignUpForm::signUp(){

    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();
    QString fullName = ui->lineEditFullName->text();
    QString email = ui->lineEditEmail->text();
    QString age = ui->lineEditAge->text();
    QString gender = ui->comboBoxGender->currentText();

    if(username.isEmpty() || password.isEmpty() || fullName.isEmpty() || email.isEmpty() || age.isEmpty() || gender.isEmpty()){
        QMessageBox::critical(this, "wrong", "please fill all the lines");
        return;
    }
    QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");

    if(!emailRegex.match(email).hasMatch()){
        QMessageBox::critical(this, "wrong", "please enter a valid emial");
        return;
    }
    bool isNumber;
    int agenum = age.toInt(&isNumber);
    if (!isNumber || agenum < 0 || agenum > 100) {
        QMessageBox::critical(this, "wrong", "please enter a valid age(between 0 and 100)");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);




    fstream file("db.txt", ios::in);



    string line;
    while (getline(file, line)) {
        istringstream strstream(line);
        string prevUser;
        strstream >> prevUser;
        if(prevUser == username.toStdString()){
            QMessageBox::warning(this, "wrong", "username already exists");
            file.close();
            return;
        }
    }
    file.close();
    file.open("db.txt", ios::app);



    file << username.toStdString() <<" " <<passwordHash.toHex().toStdString() << "\t"<<fullName.toStdString() << "\t" << email.toStdString() << "\t" << age.toStdString() << "\t" << gender.toStdString()<<endl;
    QMessageBox::information(this, "success", "signed up successfully");
}
