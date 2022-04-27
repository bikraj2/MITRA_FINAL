#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_Profile_clicked()
{
    profilewindow=new Dialog2(this);
    profilewindow->show();
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

