#ifndef SYLLABUS_H
#define SYLLABUS_H

#include <QDialog>

namespace Ui {
class syllabus;
}

class syllabus : public QDialog
{
    Q_OBJECT

public:
    explicit syllabus(QWidget *parent = nullptr);
    ~syllabus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::syllabus *ui;
};

#endif // SYLLABUS_H
