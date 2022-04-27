#include "dialog1.h"
#include "ui_dialog1.h"
#include <QtSql>
#include "mainwindow.h"
extern QString username;
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    QSqlQuery pic;
    QString pic_name;
    pic.exec("select Profile_picture from users where username='"+username+"'");
    pic.next();
    pic_name=pic.value(0).toString();
    ui->profile->setStyleSheet("image: url(:/profile_pictures/proflies/"+pic_name+");min-width:170px;min-height:170px;");

    QSqlQuery qry;
    QString name="select full_name from users where username='"+username+"'";
    qry.exec(name);
    qry.next();
    QString display_name = qry.value(0).toString();
    display_name=display_name.split(" ")[0];
    ui->display_name->setText(display_name);
}

Dialog1::~Dialog1()
{
    delete ui;
}



void Dialog1::on_pushButton_3_clicked()
{
    hide();
    todo1= new todo(this);
    todo1->show();
}


void Dialog1::on_pushButton_2_clicked()
{
    hide();
    noteMaking = new notes(this);
    noteMaking->show();
}


void Dialog1::on_pushButton_clicked()
{
    player = new music(this);
    hide();
    player->show();
}


<<<<<<< HEAD
void Dialog1::on_logout_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

=======
void Dialog1::on_change_clicked()
{
    QString names[] ={"0.png","1.png","2.png","3.png","4.png","5.png","6.png","7.png","8.png","9.png"};
    static int i ;
    i=i+1;
    if(i>9)
    {
        i=i%10;
    }
    QSqlQuery qry;
    qry.prepare("update users "
                "set Profile_picture='"+names[i]+"'"
                "where username = '"+username+"'");
    if(qry.exec())
;
        else
        qDebug()<<qry.lastError().text();
    ui->profile->setStyleSheet("image: url(:/profile_pictures/proflies/"+names[i]+");min-width:170px;min-height:170px;");


}
>>>>>>> 7262b4c4e573e0b99cf543c8f3c33d6bedba64cf
