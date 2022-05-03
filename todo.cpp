#include "todo.h"
#include "ui_todo.h"
#include "taskadder.h"
#include "syllabus.h"
#include "mainwindow.h"
#include<QMessageBox>
#include<QtSql>

QString cs5="QPushButton {"
        "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 #0677A1, stop:1 #2D4159);;color:white;font: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:10; padding-left:35;padding-right:35;"
    "}"
     "QPushButton:hover {"
        "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 #2D4159, stop:1 #0677A1);"
        "color: white;"
        "min-height:50;min-width:120;"
     "}";

QString cs6="QPushButton {"
        "max-width:20;background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 #0677A1, stop:1 #2D4159);;\ncolor:white;border-radius: 10px;padding:8;"
    "}"
     "QPushButton:hover {"
        "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 #2D4159, stop:1 #0677A1);"
        "color:white;"
     "}";
todo::todo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todo)
{
    ui->setupUi(this);
    this->setWindowTitle("Todo List");

    ui->pushButton_27->setStyleSheet(cs5);
    ui->pushButton_26->setStyleSheet(cs5);
    ui->task_adder->setMaxLength(21);

    MainWindow x;
    x.db_conn_open();
    load_not_started();
    load_in_progress();
    load_completed();

}

todo::~todo()
{
    delete ui;
}
void todo::on_pushButton_clicked()
{
    /*taskadder AddNewTask;
    AddNewTask.setModal(true);
    AddNewTask.exec();*/
}

void todo::on_pushButton_21_clicked()
{
    syllabus Adder;
    Adder.setModal(true);
    Adder.exec();
}


void todo::on_pushButton_26_clicked()
{
    QWidget * parent1 =this->parentWidget();
    hide();
    parent1->show();
}


bool todo::on_pushButton_27_clicked()
{
    extern QString username;


    QString task=ui->task_adder->text();
    if(task=="")
    {
        QMessageBox::warning(this,"ERROR","Feilds cannot be empty");
        return true;
    }
    QSqlQuery qry,check1,check2;

    QString check1_qry="Select * from not_started where username = '"+username+"' and taskname='"+task+"'";

    QString check2_qry="Select * from on_going where username = '"+username+"' and taskname='"+task+"'";
    if(check1.exec(check1_qry))
    {

        int loop1=0;
         while (check1.next())
        {
                loop1+=1;
        }

         if(loop1>=1)
         {
             QMessageBox::warning(this,"Similar task detected","Make sure you enter a different task");
             return false;
         }
    }
    else
        qDebug()<<check1.lastError().text();
    if(check2.exec(check2_qry))
    {
        int loop1=0;
         while (check2.next())
        {
                loop1+=1;
        }

         if(loop1>=1)
         {
             QMessageBox::warning(this,"Similar task detected","Make sure you enter a different task");
             return false;
         }
    }
    repaint();
    QString query="INSERT into  not_started (taskname,username) VALUES ('"+task+"','"+username+"')";
    qry.prepare(query);
    if(qry.exec())
    {
        qDebug()<<"Done Successfully";
    }
     else
    {
        qDebug()<< qry.lastError().text();
        return true;
    }
    ui->task_adder->setText("");
  load_not_started();
    return true;
}

void todo::load_not_started()
{
    extern QString username;

    pos1++;
    QGridLayout* not_started =new QGridLayout(this);
    QWidget * widgets = new QWidget(this);
    QScrollArea * area = ui->not_started;
    area->setStyleSheet("background-color:white; padding:0; margin:0;");
    widgets->setLayout(not_started);
    area->setWidget(widgets);

    QSqlQuery get_data;
    QString qry="Select taskname from not_started where username ='"+username+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new QHBoxLayout(this);
               QLabel * title = new QLabel;
               QPushButton *details = new QPushButton(this);
               details->setText(">");
               QSize size= QSize(4,4);
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color: #2f455c;\nfont-size: 20px ;\nfont: bold large;max-width:200;");
               details->setStyleSheet(cs6);
               not_started->addLayout(taskname,pos1,0);
               ui->task_adder->setText("");
               connect(details,&QPushButton::clicked,[=](){

                   QSqlQuery delete_;
                   QString delete_qry="Delete from not_started where taskname='"+task+"' and username = '"+username+"'";
                   QSqlQuery insert;
                   QString insert_qry="INSERT INTO on_going (taskname,username) values ('"+task+"','"+username+"')";
                   delete_.exec(delete_qry);

                   if(insert.exec(insert_qry))
                   {
                       if(delete_.exec(delete_qry))
                       {
                           qDebug()<<"Insert";
                           pos1=0;
                           pos2=0;
                           load_not_started();
                           load_in_progress();
                           load_completed();
                       }
                   }
                           else
                   {
                           qDebug()<<"Not inserted";
                   }
               });
               pos1+=1;
           }
    }


}
void todo::load_in_progress()
{
    extern QString username;
    QString table_name=username+"_on_going";
    pos2++;
    QGridLayout* not_started = new QGridLayout(this);
    QWidget * widgets = new QWidget;
    QScrollArea * area = ui->on_going;
    widgets->setLayout(not_started);
    area->setWidget(widgets);

    QSqlQuery get_data;
    QString qry="Select taskname from on_going where username = '"+username+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new QHBoxLayout(this);
               QLabel * title = new QLabel(this);
               QPushButton *details = new QPushButton(this);
               details->setText(">");
               QSize size= QSize(4,4);
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color: #2f455c;\nfont-size: 20px ;\nfont: bold large;max-width:200;");
               details->setStyleSheet(cs6);
               not_started->addLayout(taskname,pos2,0);
               ui->task_adder->setText("");
               connect(details,&QPushButton::clicked,[=](){

                   QSqlQuery delete_;
                   QString delete_qry="Delete from on_going where taskname='"+task+"' and username ='"+username+"'";
                   QSqlQuery insert;
                   QString insert_qry="INSERT INTO completed (taskname,username) values ('"+task+"','"+username+"')";
                   if(delete_.exec(delete_qry))
                   {
                       qDebug()<<"Deleted my g";
                   }
                   else
                   {
                       qDebug()<<"NOt delered"+delete_.lastError().text();
                   }

                   if(insert.exec(insert_qry))
                   {
                       if(delete_.exec(delete_qry))
                       {
                           qDebug()<<"Insert";
                           pos1=0;
                           pos2=0;
                           load_not_started();
                           load_in_progress();
                           load_completed();
                       }
                   }
                           else
                   {
                           qDebug()<<"Not inserted";
                   }
               });
               pos2+=1;
                }
}
    pos1=0;
    pos2=0;
}
void todo:: load_completed()
{
    extern QString username;

    QGridLayout* completed = new QGridLayout(this);
    QWidget * widgets = new QWidget(this);
    QScrollArea * area = ui->completed;
    widgets->setLayout(completed);
    area->setWidget(widgets);
    QSqlQuery get_data;
    QString qry="Select taskname from completed where username='"+username+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new QHBoxLayout(this);
               QLabel * title = new QLabel(this);
               QPushButton *details = new QPushButton(this);
               details->setStyleSheet("min-width: 150px;");
               QSize size= QSize(4,4);
               details->setText("X");
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color: #2f455c;\nfont-size: 20px ;\nfont: bold large;max-width:200;");
               details->setStyleSheet(cs6);
               completed->addLayout(taskname,pos3,0);
               ui->task_adder->setText("");
               connect(details,&QPushButton::clicked,[=](){

                   QSqlQuery delete_;
                   QString delete_qry="Delete from completed where taskname='"+task+"' and username ='"+username+"'";

                   if(delete_.exec(delete_qry))
                   {
                       qDebug()<<"Deleted my g";
                   }
                   else
                   {
                       qDebug()<<"NOt delered"+delete_.lastError().text();
                   }


                       if(delete_.exec(delete_qry))
                       {
                           qDebug()<<"Insert";
                           pos1=0;
                           pos2=0;
                           pos3=0;
                           load_not_started();
                           load_in_progress();
                           load_completed();
                       }


               });
               pos3+=1;
                }


    pos1=0;
    pos2=0;
    pos3=0;
}
}
int todo:: pos1=0;
int todo:: pos2=0;
int todo:: pos3=0;
