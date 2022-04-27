#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>
#include<timer.h>
#include<QAbstractSlider>
#include<QToolButton>
#include<QStyle>
#include<QSlider>
#include<QMessageBox>
#include<QTimer>
#include<QFont>
#include<QElapsedTimer>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
class QMediaPlaylist;
QT_END_NAMESPACE

namespace Ui
{

class music;

}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();

    float volume();
    int millisecond,  minute , second =0;
public slots:

    //void setState(QMediaPlayer::PlaybackState state);
    QString intToQString(int num);

signals:
    void play();
   // void pause();
    //void start();
   // void stop();
    void next();
    void previous();


private slots:
    void on_startButton_clicked();
    void on_previousButton_clicked();

    void on_stopButton_clicked();
    void on_Pomodoro_backButton_clicked();


    //float  onVolumeSliderValueChanged();

   // void on_sliderProgress_sliderMoved(int position);


    //void on_durationChanged(qint64 position);
    //void on_positionChanged(qint64 position);




    //void on_listWidget_itemPressed(QListWidgetItem *item);




    //void playClicked();


    //void on_timerButton_clicked();
    void  on_nextButton_clicked();

    void on_pushButton1_clicked();
    void changeTime();

    void on_pushButton2_clicked();
    void start();
     void stop();
    void reset();

    void on_pushButton3_clicked();

private:

    static int count;
    Ui::music *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;
    //timer *timerwindow;
   // QAbstractSlider *sliderVolume = nullptr;
    //QAbstractButton *playButton = nullptr;
   //QAbstractButton *stopButton = nullptr;
    //QAbstractButton *nextButton = nullptr;
    //QAbstractButton *previousButton = nullptr;
    //QAbstractButton *muteButton = nullptr;
    //QMediaPlayer::PlaybackState playerState = QMediaPlayer::StoppedState;
    //QMediaPlaylist *playlist = nullptr;

    QTimer * timer1;
    //QElapsedTimer *timer2;


};

#endif // MUSIC_H






