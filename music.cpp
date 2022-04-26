#include "music.h"
#include "ui_music.h"
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QPushButton>
#include<QAction>
music::music(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);
    this->setWindowTitle("Music");


    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(changeTime()));
    player->setAudioOutput(audio);

    //playButton = new QToolButton(this);
    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    QFont font = ui->label1->font();
    font.setBold(true);
    font.setPointSize(40);
    ui->label1->setFont(font);
    ui->label1->setText(intToQString(minute)+":"+intToQString(second));


    connect(ui->playButton, &QAbstractButton::clicked, this, &music::on_startButton_clicked);

    //stopButton = new QToolButton(this);
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));


    connect(ui->stopButton, &QAbstractButton::clicked, this, &music::on_stopButton_clicked);

    //extButton = new QToolButton(this);
    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(ui->nextButton, &QAbstractButton::clicked, this, &music::on_nextButton_clicked);

    //previousButton = new QToolButton(this);
    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    //previousButton ->setIcon(style()->standardIcon(Qstyle::PM_ButtonIconsize());

    connect(ui->previousButton, &QAbstractButton::clicked, this, &music::on_previousButton_clicked);




    QAction *sc = new QAction(this);
    sc->setShortcut(Qt::Key_Space);

    connect(sc, SIGNAL(triggered()), this, SLOT(start()));
    connect(sc, SIGNAL(triggered()), this, SLOT(on_startButton_clicked()));

    this->addAction(sc);

   // muteButton = new QToolButton(this);
   // muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

   // connect(muteButton, &QAbstractButton::clicked, this, &music::muteClicked);

//    sliderVolume = new QSlider(Qt::Horizontal, this);
//    sliderVolume->setRange(0, 100);

    //connect(sliderVolume, &QSlider::valueChanged, this, &music::onVolumeSliderValueChanged);

//    QBoxLayout *layout = new QHBoxLayout;
//    layout->setContentsMargins(100, 100, 100, 100);
//      layout->addWidget(stopButton);
//      layout->addWidget(previousButton);
//      layout->addWidget(playButton);
//      layout->addWidget(nextButton);
//      setLayout(layout);

      //nextButton->setFixedSize(50,50);
      //previousButton->setFixedSize(50,50);
     // layout->addWidget(m_muteButton);
      //layout->addWidget(sliderVolume);
//   layout->addWidget(m_rateBox);


    //  connect (player, &QMediaPlayer::positionChanged, this, &music:: on_positionChanged);
     // connect (player, &QMediaPlayer::durationChanged, this, &music:: on_durationChanged);
      //connect (audio , &QSlider:: valueChanged,this, &music:: on_sliderVolume_valueChanged);

};
music::~music()
{

    delete ui;
}

//void music::playClicked()
//{
//    switch (playerState) {
//    case QMediaPlayer::StoppedState:
//    case QMediaPlayer::PausedState:
//        emit play();
//        break;
//    case QMediaPlayer::PlayingState:
//        emit pause();
//        break;
//    }
//}

//void music::setState(QMediaPlayer::PlaybackState state)
//{
//    if (state != playerState) {
//        playerState = state;

//        switch (state) {
//        case QMediaPlayer::StoppedState:
//            stopButton->setEnabled(false);
//            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//            break;
//        case QMediaPlayer::PlayingState:
//            stopButton->setEnabled(true);
//            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
//            break;
//        case QMediaPlayer::PausedState:
//            stopButton->setEnabled(true);
//            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//            break;
//        }
//    }
//}
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
void music::on_startButton_clicked() // for music
{
    // load and play the file

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





        player->play();
        qDebug()<<"hello";
}



void music::on_stopButton_clicked() // for music
{
    player->stop();


}
void music::on_Pomodoro_backButton_clicked()
{
    this->hide();
    QWidget * parent  = this->parentWidget();
    parent->show();
}


//void music:: on_positionChanged(qint64 position)
//{
//    ui->sliderProgress->setValue(position);
//}
//void music:: on_durationChanged(qint64 position)
//{
//    ui->sliderProgress->setMaximum(position);
//}

//float music::onVolumeSliderValueChanged()
//{
//    qreal linearVolume =  QAudio::convertVolume(sliderVolume->value() / qreal(100),
//                                                QAudio::LogarithmicVolumeScale,
//                                                QAudio::LinearVolumeScale);

//    return linearVolume;

//}




//float music::volume() const
//{
//    qreal linearVolume =  QAudio::convertVolume(audio-> / qreal(100),
//                                                QAudio::LogarithmicVolumeScale,
//                                                QAudio::LinearVolumeScale);

//    return linearVolume;
//}

//float PlayerControls::volume() const
//{
//    qreal linearVolume =  QAudio::convertVolume(m_volumeSlider->value() / qreal(100),
//                                                QAudio::LogarithmicVolumeScale,
//                                                QAudio::LinearVolumeScale);

//    return linearVolume;
//}

//void PlayerControls::setVolume(float volume)
//{
//    qreal logarithmicVolume = QAudio::convertVolume(volume,
//                                                    QAudio::LinearVolumeScale,
//                                                    QAudio::LogarithmicVolumeScale);

//    m_volumeSlider->setValue(qRound(logarithmicVolume * 100));
//}
//void music::on_sliderProgress_sliderMoved(int position)
//{
//    player->setPosition(position);
//}








void music::start(){
    timer1->start(10);
    ui->pushButton1->setText("Stop");
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(stop()));


}

void music::stop(){
    timer1->stop();
    ui->pushButton1->setText("Start");
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(start()));

}

void music::reset(){
    millisecond = second = minute = 0;

   ui->label1->setText(intToQString(minute)+":"+intToQString(second));
    stop();

}

//void music::on_timerButton_clicked()
//{
//    hide();
//    timerwindow  = new timer(this);
//    timerwindow->show();
//}


int music:: count=0;


void music:: changeTime(){

        millisecond++;
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

void music::on_pushButton1_clicked()
{   timer1->start(10);
    ui->pushButton1->setText("Stop");
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(start()));
//    if(assert(ui->pushButton1->text()=="Start")){
//        qDebug()<<"hello";

//    }


}
void music::on_pushButton2_clicked()
{
    millisecond = second = minute = 0;
    ui->label1->setText(intToQString(minute)+":"+intToQString(second));
    timer1->stop();

}


