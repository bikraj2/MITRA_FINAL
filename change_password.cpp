#include "change_password.h"
#include "ui_change_password.h"
#include<QtSql>
#include<QMessageBox>
#include<QSystemTrayIcon>
#include<QIcon>
change_password::change_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_password)
{
    ui->setupUi(this);
    ui->mesage->setText("");
    //QIcon * qApp = new QIcon(this);
    //qApp->setWindowIcon("C:/Users/Lenovo/OneDrive/Desktop/phooo.png");
}
change_password::~change_password()
{
    delete ui;
}

bool change_password::on_pushButton_clicked()
{

    extern QString  username2,DOB,nickname;
    QString new_p,confirm_p;
    new_p=ui->new_p->text();
    confirm_p=ui->confirm_p->text();
    QRegularExpression password_pattern("^.*(?=.{8,})(?=.*[a-zA-Z])(?=.*\\d)(?=.*[!@#$%^&-+=()])(?=\\S+$).*$");
    QRegularExpressionMatch password_is_valid = password_pattern.match(new_p);

    if(new_p!=confirm_p)
    {
        ui->mesage->setText("The passwords donot match");
        ui->new_p->setText("");
        ui->confirm_p->setText("");
        return 0;
    }

    if(password_is_valid.hasMatch())
    {
        encrypt(new_p);
        QSqlQuery change;

        QString qry= "Update users set password1 ='"+new_p+"' where username= '"+username2+"'";
        if (change.exec(qry))
        {
            QMessageBox::information(this,"Done","Your password is changed successfully");
            this->hide();
            QWidget *parent = this->parentWidget();
            parent->show();
        }
        else
        {
             QMessageBox::information(this,"Done",change.lastError().text());
        }
    }
    else
    {
        QMessageBox::warning(this,"Invalid Password","Your password must: \n include a letter,symbol and a number\n be at least 8 character long");
    }
}
void change_password :: encrypt(QString &string_encrypt)
{

    QString p_text = string_encrypt;
    int k=598658, value,ascii;
    for (int i = 0; i < p_text.size(); i++)
    {
        ascii = (p_text[i]).QChar::unicode();
        if (ascii >= 48 && ascii <= 57)
        {
            value = ((ascii + k - 48) % 10 + 48);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            value = ((ascii + k - 65) % 26 + 65);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            value = ((ascii + k - 97) % 26 + 97);
            string_encrypt[i] = static_cast<char>(value);
        }
        else
        {
            string_encrypt[i] = static_cast<char>(ascii);
        }
    }
}

