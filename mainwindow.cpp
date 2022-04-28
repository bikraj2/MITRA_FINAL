#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
#include<QtSql>
#include<QFileInfo>
#include<QtDebug>
#include<iostream>
#include<QAction>
#include<QKeyEvent>
QSqlDatabase info  =  QSqlDatabase::addDatabase("QSQLITE");
QString username;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db_conn_open();

    setTable();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_login_3_clicked()
{
 username = ui->username_3->text();
    QString password = ui->Password_3->text();
    encrypt(password);
    QSqlQuery qry;
    if(qry.exec("Select * from users where username= '"+username+"' and password1= '"+password+"'"))
    {
        int count =0;
        while(qry.next())
        {
            count++;
        }
        if (count<1)
        {
            QMessageBox:: warning(this,"Incorrect Credentials","Please make sure you have entered the correct username and passowrd.");
        }
        else if (count>=1)
        {
            hide();
            firstwindow = new Dialog1(this);
            ui->username_3->setText("");
            ui->Password_3->setText("");
            firstwindow->show();
        }
    }
    else
    {
        QMessageBox:: warning(this,"hey",qry.lastError().text());
    }
}
void MainWindow::on_pushButton_singup_3_clicked()
{
    hide();
    register1 =  new signup(this);
    register1->show();
}
void MainWindow:: db_conn_open()
{

    QDir data("C:/Db");
        if (!data.exists())
        {
            data.mkpath("C:/D");
        }
        QSqlDatabase info  =  QSqlDatabase::addDatabase("QSQLITE");
        info.setDatabaseName("/Users/priyanshu/ProjectMitra/Mitra_Final/users.db");
        info.open();
        if(!info.open())
        {
            qDebug() << "hey sorry";
        }

}
void MainWindow:: db_conn_close()
{
info.close();
QSqlDatabase info  =  QSqlDatabase::addDatabase("QSQLITE");
}
bool MainWindow :: setTable()
{
    QSqlQuery table1;
    QSqlQuery not_started,on_going,completed;
    QString qry="Create Table users"
            "("
                "full_name varchar(50),"
                "nickname varchar(50) PRIMARY KEY,"
                "username varchar(50),"
                "password1 varchar(50),"
                "DOB date"
            ");";
    table1.exec(qry);
        QString not_started_qry="Create Table not_started (username varchar (50)  ,taskname varchar(100),FOREIGN KEY (username) references users(username))",on_going_qry="Create Table on_going (username varchar (50)  ,taskname varchar(100),FOREIGN KEY (username) references users(username))",completed_qry="Create Table completed (username varchar (50)  ,taskname varchar(100),FOREIGN KEY (username) references users(username))";
        if(not_started.exec(not_started_qry))
        {
            qDebug()<<"DOne";
        }
        else
        {
            qDebug()<<not_started.lastError().text();
        }
        if(on_going.exec(on_going_qry))
        {
            qDebug()<<"ongoing created";
        }
        else
        {
            qDebug()<<on_going.lastError().text();
        }
        if(completed.exec(completed_qry))
        {
            qDebug()<<"completed created";
        }
        else
        {
            qDebug()<<completed.lastError().text();
        }
    return false;
}
void MainWindow::encrypt(QString &string_encrypt){

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


void MainWindow::on_pushButton_clicked()
{
    hide();
    password1=new ForgotPassword(this);
    password1->show();
}
void MainWindow::keyPressEvent(QKeyEvent * e)
{
    if (e->key()== Qt::Key_Enter)
    {

       }

}


