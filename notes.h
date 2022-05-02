#ifndef NOTES_H
#define NOTES_H

#include <QMainWindow>

namespace Ui {
class notes;
}

class notes : public QMainWindow
{
    Q_OBJECT

public:
    explicit notes(QWidget *parent = nullptr);
    ~notes();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_Notepad_triggered();

    void on_actionClose_triggered();

private:
    Ui::notes *ui;
   // string variable
    QString file_path; // private access modifier
};

#endif // NOTES_H
