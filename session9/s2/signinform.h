#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QWidget>

namespace Ui {
class SignInForm;
}

class SignInForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignInForm(QWidget *parent = nullptr);
    ~SignInForm();


private slots:
    void login();
private:
    Ui::SignInForm *ui;
};

#endif
