#ifndef TODO_H
#define TODO_H

#include <QDialog>
#include <QScrollArea>

namespace Ui {
class todo;
}

class todo : public QDialog
{
    Q_OBJECT

public:
    static int pos1;
    static int pos2;
    static int pos3;
    explicit todo(QWidget *parent = nullptr);


    ~todo();
public slots:


private slots:
   void on_pushButton_26_clicked();
   bool on_pushButton_27_clicked();
   void load_not_started();
   void load_in_progress();
   void load_completed();
private:
    Ui::todo *ui;
};



#endif // TODO_H
