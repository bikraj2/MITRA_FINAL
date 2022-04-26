#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    bool on_pushButton_clicked();
    void encrypt(QString &string_encrypt);

    void on_pushButton_2_clicked();

private:
    Ui::signup *ui;

};

#endif // SIGNUP_H
