#include "music.h"
#include "ui_music.h"
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QPushButton>
#include<QAction>
#include<QPixmap>
#include<QSystemTrayIcon>

music::music(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);

    this->setWindowTitle("Music");

    QPixmap pix(":/icon/icon/phooo.png");
    ui->label2->setPixmap(pix.scaled(500,500, Qt::KeepAspectRatio));


    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,SIGNAL(timeout()),this,SLOT(changeTime()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(breaktime()));


    player->setAudioOutput(audio);

    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    QFont font = ui->label1->font();
    font.setBold(true);
    font.setPointSize(40);
    ui->label1->setFont(font);
    ui->label1->setText(intToQString(minute)+":"+intToQString(second));


    connect(ui->playButton, &QAbstractButton::clicked, this, &music::on_startButton_clicked);


    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));


    connect(ui->stopButton, &QAbstractButton::clicked, this, &music::on_stopButton_clicked);


    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(ui->nextButton, &QAbstractButton::clicked, this, &music::on_nextButton_clicked);


    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));


    connect(ui->previousButton, &QAbstractButton::clicked, this, &music::on_previousButton_clicked);




    QAction *sc = new QAction(this);
    sc->setShortcut(Qt::Key_Space);

   // connect(sc, SIGNAL(triggered()), this, SLOT(start()));
    connect(sc, SIGNAL(triggered()), this, SLOT(on_startButton_clicked()));

    this->addAction(sc);

};
music::~music()
{

    delete ui;
}

void music :: on_nextButton_clicked(){

    count=count%6;
    count++;
   if(count  ==1){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));
 }
if(count==2){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));
}
if(count==3){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));
}
if(count==4){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));
}
if(count==5){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));
}
if(count<0)
{
    count=5;
}
player->play();
}
void music :: on_previousButton_clicked(){
    qDebug()<<"as";
    count=count%6;
    count--;
   if(count  ==1){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));
 }
if(count==2){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));
}
if(count==3){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));
}
if(count==4){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));
}
if(count==5){
    player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));
}
if(count<0)
{
    count=5;
}
player->play();


}
void music::on_startButton_clicked()
{


   if(count  ==0){
     player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));
    }
   if(count==1){
     player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));
   }
   if(count==2){
     player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));
    }
    if(count==3){
      player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));
     }
    if(count==4){
      player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));
     }
     if(count<0)
     {
        count=5;
      }


       timer1->start(10);

        player->play();

}



void music::on_stopButton_clicked() {
    player->stop();
    timer1->stop() ;


}
void music::on_Pomodoro_backButton_clicked()
{
    this->hide();
    QWidget * parent  = this->parentWidget();
    parent->show();
}

int music:: count=0;


void music:: changeTime(){


        int option;


        millisecond++;
        QMessageBox msgBox;
        msgBox.setText("Great Work, Champ!");
        msgBox.setText("Do you want a break now? ");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
        if(minute==25 && second ==0)
        {

            option = msgBox.exec();

            if(option== QMessageBox::Yes){

                msgBox.close();
                breaktime();
            }
            else if(option== QMessageBox:: No){
                msgBox.close();
                player->play();
                breaktime();


             }




        }
        if(millisecond>=100){
            millisecond=0;
            second++;
        }
        if(second>=60){
            second=0;
            minute++;
        }


        ui->label1->setText(intToQString(minute)+":"+intToQString(second));

    }

QString music:: intToQString(int num){
    QString str = QString::number(num);

    if(str.length() == 1){
        str = "0"+str;
    }

    return str;
}

void music:: alert(){
    if(minute==5 && second == 0){
        QMessageBox m1 ;
        m1.setText("Break Finished");
        m1.exec();
    }
}
void music:: breaktime(){
    do{


    minute = 4;
    second = 59;

    connect(timer2,SIGNAL(timeout()),this,SLOT(breaktime()));
    timer2->start(10);


    if(second<=0){
        minute--;
        second = 59;
    }



    ui->label1->setText(intToQString(minute)+":"+intToQString(second));
   }
    while(second==0 && minute ==0);

}
void music::on_pushButton1_clicked()

{   timer1->start(10);

}
void music::on_pushButton2_clicked()
{
    millisecond = second = minute = 0;
    ui->label1->setText(intToQString(minute)+":"+intToQString(second));
    timer1->stop();
    player->stop();

}

void music::on_pushButton3_clicked()
{
    player->stop();
    timer1->stop();

}

