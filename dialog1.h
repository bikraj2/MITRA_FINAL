#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include"dialog2.h"
#include "todo.h"
#include"notes.h"
#include"music.h"
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:




    void on_pushButton_3_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_logout_clicked();
    void on_change_clicked();

    void on_display_name_linkActivated(const QString &link);
    void set_quotes();
    void on_edit_clicked();
    void load_bio();

private:
    Ui::Dialog1 *ui;
     Dialog2 *profilewindow;
     todo* todo1;
     notes * noteMaking;
     music * player;
};

#endif // DIALOG1_H
