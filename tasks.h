#ifndef TASKS_H
#define TASKS_H

#include <QDialog>

namespace Ui {
class tasks;
}

class tasks : public QDialog
{
    Q_OBJECT

public:
    explicit tasks(QWidget *parent = nullptr);
    ~tasks();

private:
    Ui::tasks *ui;
};

#endif // TASKS_H
