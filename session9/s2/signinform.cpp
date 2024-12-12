#include "signinform.h"
#include "ui_signinform.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <fstream>
#include <sstream>
using namespace std;

SignInForm::SignInForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignInForm)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &SignInForm::login);
}

SignInForm::~SignInForm()
{
    delete ui;
}


void SignInForm::login(){
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "wrong", "please fill all the lines");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    fstream file;
    file.open("db.txt", ios::in);

    string line, prevUser, prevPass;
    while (getline(file, line)) {
        stringstream strstream(line);
        getline(strstream, prevUser, '\t');
        getline(strstream, prevPass, '\t');
        //qDebug()<<prevPass<<"\n"<<passwordHash.toHex().toStdString();
        if(prevUser == username.toStdString() && passwordHash.toHex().toStdString() == prevPass){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("logged in successfuly");
            msgBox.setWindowTitle("logged in");
            msgBox.setStyleSheet("QMessageBox { background-color: #e5f7e5; }");
            msgBox.exec();
            return;
        }
    }
    QMessageBox::critical(this, "wrong", "invalid username or password");
}
