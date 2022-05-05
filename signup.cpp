#include "signup.h"
#include "ui_signup.h"
#include <QtSql>
#include<QMessageBox>
#include<mainwindow.h>
#include<QAction>
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("SignUp");


}

signup::~signup()
{
    delete ui;
}

bool signup::on_pushButton_clicked()
{
    QString full_name,nickname,email,username,password,date;
    full_name=ui->lineEdit->text();
    nickname=ui->lineEdit_2->text();
    username=ui->lineEdit_5->text();
    password=(ui->lineEdit_6->text());
    date = ui->lineEdit_4->text();
    if(full_name=="" || nickname ==""||username==""||password==""||date=="")
    {
        QMessageBox::warning(this,"Incomplete information","Make sure you have entered all the fields.");
        return true;

    }
    QRegularExpression username_pattern("^[a-zA-Z0-9_-]{5,10}$");//only includes alphabets or digits or underscore or hyphen; 5 to 10 characters
    QRegularExpressionMatch username_is_valid = username_pattern.match(username);

    QRegularExpression password_pattern("^.*(?=.{8,})(?=.*[a-zA-Z])(?=.*[0-9])(?=.*[!@#$%^&-+=()\\?]).*$");
    QRegularExpressionMatch password_is_valid = password_pattern.match(password);
    if(password_is_valid.hasMatch()&&username_is_valid.hasMatch())
    {
        QSqlQuery qry1;
        if(qry1.exec("Select * from users where username='"+username+"'"))
        {
            int loop=0;
            while (qry1.next())
            {

                loop+=1;

            }
          if(loop>=1)
            {
                QMessageBox::warning(this,"User already registered!","Please try a different username.");
                return true;
            }
        }
        encrypt(password);
        QSqlQuery  qry;
        qry.prepare("Insert into users (full_name,nickname,username,password1,DOB) values('"+full_name+"','"+nickname+"','"+username+"','"+password+"','"+date+"')");
        if(qry.exec())
        {
            QMessageBox::information(this,"User Registered","You have been registered.");
            this->hide();
            QWidget *parent = this->parentWidget();
            parent->show();
        }
        else
        {
            qDebug()<<qry.lastError().text();
        }
    }
    else{
    if (!username_is_valid.hasMatch() && !password_is_valid.hasMatch())
    {QMessageBox::warning(this, "Invalid username and password", "Your username:\n  - may include letters, numbers, underscore or hyphen.\n  - needs to include 5 to 10 characters.\n\nYour password must :\n  - include at least one letter, number and symbol.\n  - be at least 8 characters long.");
    }
    else if (!username_is_valid.hasMatch())
    {QMessageBox::warning(this, "Invalid username", "Your username:\n  - may include letters, numbers, underscore or hyphen.\n  - needs to include 5 to 10 characters.");
    ;
    }
    else if (!password_is_valid.hasMatch())
    {QMessageBox::warning(this, "Invalid password", "Your password must:\n  - include at least one letter, number and symbol.\n  - be at least 8 characters long.");
    }
}
    return false;
}
void signup::encrypt(QString &string_encrypt)
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



void signup::on_pushButton_2_clicked()
{

    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

