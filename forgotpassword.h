#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H
#include"change_password.h"
#include <QDialog>

namespace Ui {
class ForgotPassword;
}

class ForgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotPassword(QWidget *parent = nullptr);
    ~ForgotPassword();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ForgotPassword *ui;
    change_password * chng;
};

#endif // FORGOTPASSWORD_H
