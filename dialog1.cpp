#include "dialog1.h"
#include "ui_dialog1.h"
#include <QtSql>
#include "mainwindow.h"
#include<QTextEdit>
#include<QLineEdit>
#include<time.h>
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
    load_bio();
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
    set_quotes();
}
Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1:: load_bio()
{
    QSqlQuery qry;
    QString qry1,bio,dob,hobbies,username;
    qry1="SELECT DOB,BIO ,Hobbies  from users where username='"+::username+"'";
    qry.exec(qry1);
    qry.next();
    dob=qry.value(0).toString();
    bio=qry.value(1).toString();
    hobbies=qry.value(2).toString();
    username="@"+::username;
    ui->bio->setText(bio);
    ui->dob->setText(dob);
    ui->hobbies->setText(hobbies);
    ui->username->setText(username);
}
void Dialog1::set_quotes()
{


    srand(time(0));
    int x = rand()%23;
    QString quote;
    QSqlQuery qry;
    QString quoteqry="Select * from quotes ";
    if(qry.exec(quoteqry))
    {

        for(int i=1;i<x;i++)
        {
            qry.next();
        }
        quote=qry.value(0).toString();
        ui->quotes->setText(quote);

    }
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


void Dialog1::on_edit_clicked()
{
    QWidget *window = new QWidget();
    QGridLayout * main = new QGridLayout(this);
    window->setGeometry(600,300,270,150);
    window->setWindowTitle("Edit bio");
    QHBoxLayout *bio = new QHBoxLayout(this);
    QHBoxLayout *hobbies = new QHBoxLayout(this);
    QHBoxLayout *enter_zone = new QHBoxLayout(this);
    QLabel * bio_label=new QLabel("Bio",this);
    QLabel * hobbies_label=new QLabel("Hobbies",this);
    QString enter_info="Enter your bio here";
    QLineEdit *bio_edit = new QLineEdit;
    QPushButton * enter = new QPushButton("Enter",this);

    QSpacerItem * first = new QSpacerItem(100,20);
    QSpacerItem * second = new QSpacerItem(100,20);
    QLineEdit * hobies_edit = new QLineEdit;
    connect(enter,&QPushButton::clicked,[=](){
      QSqlQuery qry;
      QString qry1,bio,hobbies;
      bio=bio_edit->text();
      hobbies=hobies_edit->text();
      qry1="update users set BIO='"+bio+"',Hobbies='"+hobbies+"' where username ='"+username+"'";
      if(qry.exec(qry1))
      {
         load_bio();
      }
      else
      {
          qDebug()<<qry.lastError().text();
      }
      window->close();
   });
    bio_edit->setMaxLength(25);
    hobies_edit->setMaxLength(25);
    bio->addWidget(bio_label,0);
    bio->addWidget(bio_edit,1);
    hobbies->addWidget(hobbies_label,0);
    hobbies->addWidget(hobies_edit,1);
    enter_zone->addItem(first);
    enter_zone->addWidget(enter,1);
    enter_zone->addItem(second);
    main->addLayout(bio,0,0);
    main->addLayout(hobbies,1,0);
    main->addLayout(enter_zone,2,0);
    window->setLayout(main);
    window->show();

}


