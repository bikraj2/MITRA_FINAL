#ifndef TASKADDER_H
#define TASKADDER_H

#include <QDialog>

namespace Ui {
class taskadder;
}

class taskadder : public QDialog
{
    Q_OBJECT

public:
    explicit taskadder(QWidget *parent = nullptr);
    ~taskadder();
private slots:
    void on_pushButton_clicked();
private:
    Ui::taskadder *ui;
};

#endif // TASKADDER_H
