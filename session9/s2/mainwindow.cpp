#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupform.h"
#include "signinform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSignUp_clicked()
{
    SignUpForm* signForm = new SignUpForm;
    signForm->show();
}


void MainWindow::on_btnLogin_clicked()
{
    SignInForm* singninform = new SignInForm;
    singninform->show();
}

