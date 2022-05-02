#include "dialog1.h"
#include "ui_dialog1.h"
#include <QtSql>
#include "mainwindow.h"
extern QString username;
QString cs2="QPushButton {"        "image:url(:/icon/icon/Blue Simple Gradient Motivation Quote Facebook Profile Frame.png);"


    "}"
     "QPushButton:hover {"
        "background-color: white;"
        "image:url(:/icon/icon/Blue Simple Gradient Motivation Quote Facebook Profile Frame (1).png);"
    "}";

QString cs3="QFrame {"
    "}"
     "QPushButton:hover {"
        "border-radius:10;"
        "background-color: #E97928;"
    "}";
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
    ui->display_name->setAlignment(Qt::AlignCenter);
    ui->change->setStyleSheet(cs2);
    ui->frame_3->setStyleSheet(cs3);
    ui->frame_4->setStyleSheet(cs3);
    ui->frame_5->setStyleSheet(cs3);

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


void Dialog1::on_logout_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void Dialog1::on_change_clicked()
{
    QString names[] ={"1.png","3.png"};
    static int i ;
    i=i+1;
    if(i>1)
    {
        i=i%2;
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

void Dialog1::on_display_name_linkActivated(const QString &link)
{
    QString names[] ={"1.png","3.png"};
    static int i ;
    i=i+1;
    if(i>1)
    {
        i=i%2;
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

