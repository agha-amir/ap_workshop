#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
    ~SignUpForm();


private slots:
    void signUp();

private:
    Ui::SignUpForm *ui;
};

#endif
