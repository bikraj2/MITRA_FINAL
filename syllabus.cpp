#include "syllabus.h"
#include "ui_syllabus.h"
#include "todo.h"
syllabus::syllabus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::syllabus)
{
    ui->setupUi(this);
}

syllabus::~syllabus()
{
    delete ui;
}


void syllabus::on_pushButton_clicked()
{
    hide();
}






