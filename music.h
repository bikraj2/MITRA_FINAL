#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>

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


    QString intToQString(int num);
    void alert();





private slots:
    void breaktime();
    void on_startButton_clicked();
    void on_previousButton_clicked();

    void on_stopButton_clicked();
    void on_Pomodoro_backButton_clicked();








    void  on_nextButton_clicked();

    void on_pushButton1_clicked();
    void changeTime();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

private:

    static int count;
    Ui::music *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;

    QTimer * timer1;
    QTimer * timer2;



};

#endif // MUSIC_H






