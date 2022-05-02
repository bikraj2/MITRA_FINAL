#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog1.h"
#include "signup.h"
#include "forgotpassword.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void  db_conn_open();

private slots:


    void db_conn_close();
    void on_pushButton_login_3_clicked();

    void on_pushButton_singup_3_clicked();

    bool setTable();
    void encrypt(QString &string_encrypt);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog1 *firstwindow;
    signup * register1;
    ForgotPassword * password1;
    void keyPressEvent(QKeyEvent * event);

};
#endif // MAINWINDOW_H
