#include "forgotpassword.h"
#include "ui_forgotpassword.h"
#include<QtSql>
#include<QMessageBox>
QString  username2,DOB,nickname;
ForgotPassword::ForgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}


void ForgotPassword::on_pushButton_clicked()
{


    username2=ui->username3->text();
    DOB=ui->DOB->text();
    nickname=ui->Nickname->text();
    QSqlQuery forgot;
    QString qry="Select * from  users where username='"+username2+"'and DOB ='"+DOB+"' and nickname='"+nickname+"'";
    if (forgot.exec(qry))
    {
        int loop=0;
        while (forgot.next())
        {
            loop+=1;
        }
        if (loop>=1)
        {
           hide();
           chng= new change_password(this);
           chng->show();
        }
        else
        {
              QMessageBox:: warning(this,"Incorrect Credentials","The details you entered donot match.");
        }
    }

}


void ForgotPassword::on_pushButton_2_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

