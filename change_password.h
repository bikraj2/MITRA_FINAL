#ifndef CHANGE_PASSWORD_H
#define CHANGE_PASSWORD_H
#include <QDialog>

namespace Ui {
class change_password;
}

class change_password : public QDialog
{
    Q_OBJECT

public:
    explicit change_password(QWidget *parent = nullptr);
    ~change_password();

private slots:
    bool on_pushButton_clicked();
    void encrypt(QString &string_encrypt);
private:
    Ui::change_password *ui;
};

#endif // CHANGE_PASSWORD_H
