#include "taskadder.h"
#include "ui_taskadder.h"

taskadder::taskadder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskadder)
{
    ui->setupUi(this);
}

taskadder::~taskadder()
{
    delete ui;
}
void taskadder::on_pushButton_clicked()
{
    close();
}
