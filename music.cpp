#include "music.h"
#include "ui_music.h"
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPushButton>
#include <QAction>
#include <QPixmap>
#include <QSystemTrayIcon>
QString css1
{
    "QFrame {""border:none;"
     "border-radius:10px;"
    "color:white;"


        "}"
         "QPushButton:hover {"
        "border:none;"
            "border-radius:10px;"
            "background-color: #ED6605;"
        "}"

};

music::music(QWidget *parent) : QDialog(parent),
                                ui(new Ui::music)
{
    ui->setupUi(this);

    this->setWindowTitle("Pomodoro");
    ui->pushButton1->setStyleSheet(css1);
    ui->pushButton2->setStyleSheet(css1);
    ui->pushButton3->setStyleSheet(css1);





    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    timer1 = new QTimer(this);
    timer1->setTimerType(Qt::PreciseTimer);

    timer2 = new QTimer(this);
    timer2->setTimerType(Qt::PreciseTimer);
    connect(timer1, SIGNAL(timeout()), this, SLOT(changeTime()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(breaktime()));
    player->setAudioOutput(audio);

    QFont font = ui->label1->font();
    font.setBold(true);
    font.setPointSize(120);
    ui->label1->setFont(font);
    ui->label1->setText(intToQString(minute) + ":" + intToQString(second));

    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    connect(ui->playButton, &QAbstractButton::clicked, this, &music::on_playButton_clicked);
    connect(ui->stopButton, &QAbstractButton::clicked, this, &music::on_stopButton_clicked);
    connect(ui->nextButton, &QAbstractButton::clicked, this, &music::on_nextButton_clicked);
    connect(ui->previousButton, &QAbstractButton::clicked, this, &music::on_previousButton_clicked);

    QAction *sc = new QAction(this);
    sc->setShortcut(Qt::Key_Space);
    connect(sc, SIGNAL(triggered()), this, SLOT(on_playButton_clicked()));
    this->addAction(sc);

};
int music :: count = 0 ;
music::~music()
{

    delete ui;
}

void music ::on_nextButton_clicked()
{   count++;

    count = count % 6;

    if (count == 1)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));

    }

    else if (count == 2)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));

    }
    else if (count == 3)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));

    }
    else if (count == 4)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));

    }
    else if (count == 5)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));

    }



    player->play();
}
void music ::on_previousButton_clicked()
{
    count = count % 6;
    if(count<0)
    {
         count++;
    }
    if (count == 0)
    {
        qDebug()<<"1";
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));
        count++;
    }

    else if (count == 1)
    {
        qDebug()<<"2";
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));

    }
    else if (count == 2)
    {
        qDebug()<<"3";
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));

    }
    else if (count == 3)
    {
        qDebug()<<"4";
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));

    }
    else if (count == 4)
    {
        qDebug()<<"5";
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));

    }


    count--;
    player->play();
}
void music::on_playButton_clicked()
{
    count++;

    if (count == 1)
    {

        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));
    }
    else if (count == 2)
    {
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s2.mp3"));
    }
    else if (count == 3)
    {
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s3.mp3"));
    }
    else if (count == 4)
    {
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s4.mp3"));
    }
    else if (count == 5)
    {
        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s5.mp3"));
    }
    player->play();
    timer1->start(10);

}


void music::on_stopButton_clicked()
{
    player->stop();
    timer1->stop();

}
void music::on_Pomodoro_backButton_clicked()
{
    timer1->stop();
    player->stop();
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void music::changeTime()
{

    int option;

    millisecond++;
    QMessageBox msgBox;
    msgBox.setText("Great Work, Champ!");
    msgBox.setText("Do you want a break now? ");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    QMessageBox msgBox2;
    msgBox2.setText("50 minutes up!!");
    msgBox2.setText("You gotta take a break now!");
    msgBox2.setStandardButtons(QMessageBox::Ok);
    if (minute == 25 && second == 0)
    {

        option = msgBox.exec();
        switch (option)
        {
        case QMessageBox::Yes:
            msgBox.close();
            minute = second = millisecond = 0;
            ui->label1->setText(intToQString(minute) + ":" + intToQString(second));
            timer1->stop();
            bsecond = 59;
            bminute = 4;
            breaktime();
            break;

        case QMessageBox::No:
            msgBox.close();
            second++;

            break;
        }
    }

    if(minute == 50 && second ==0 )
    {
        option = msgBox2.exec();

        if(option == QMessageBox:: Yes) {
            minute = second = millisecond = 0 ;
            ui->label1->setText(intToQString(minute) + ":" + intToQString(second));
            timer1->stop();
            bsecond = 59 ;
            bminute = 4;
            breaktime();

        }




    }
    if (millisecond >= 100)
    {
        millisecond = 0;
        second++;
    }
    if (second >= 60)
    {
        second = 0;
        minute++;
    }

    ui->label1->setText(intToQString(minute) + ":" + intToQString(second));
}

QString music::intToQString(int num)
{
    QString str = QString::number(num);

    if (str.length() == 1)
    {
        str = "0" + str;
    }

    return str;
}


void music::breaktime()   // initiated when we want a break.
{

    QMessageBox breakfinish;
    breakfinish.setText("Break Finished");
    breakfinish.setStandardButtons(QMessageBox::Ok);

    timer2->start(10);
    bmillisecond++;
    if (bmillisecond >= 100)
    {
        bmillisecond = 0;
        bsecond--;
    }
    if (bsecond <= 0)
    {
        bsecond = 59;
        bminute--;
    }
    ui->label1->setText(intToQString(bminute) + ":" + intToQString(bsecond));

    if (bsecond == 0 && bminute == 0)
    {
        timer2->stop();
        bsecond = bminute == 0;
        ui->label1->setText(intToQString(bminute) + ":" + intToQString(bsecond));

        breakfinish.exec();
        timer1->start(10);
        changeTime();

        //connect(timer1,SIGNAL(timeout()),this,SLOT(breaktime()));

        //timer2->start(10);
    }
}
void music::on_pushButton1_clicked() // play button of timer.

{
    timer1->start(10);
    on_playButton_clicked();

}
void music::on_pushButton2_clicked()  // reset button of timer
{
    millisecond = second = minute = 0;
    ui->label1->setText(intToQString(minute) + ":" + intToQString(second));
    timer1->stop();
    player->stop();
}

void music::on_pushButton3_clicked()  //stop button of timer
{
    player->stop();
    timer1->stop();
}


