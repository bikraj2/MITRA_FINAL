#include "notes.h"
#include "ui_notes.h"
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>

notes::notes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notes)
{
    ui->setupUi(this);
    this->setWindowTitle("Notepad");

    this->setCentralWidget(ui->textEdit);
}

notes::~notes()
{
    delete ui;
}
void notes::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText(" ");

}


void notes::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
    QFile file (file_name);
    file_path=file_name;
    if (!file.open(QFile :: ReadOnly|QFile ::Text))
    {
        QMessageBox::warning (this,"..","file not open");
        return;
    }
    QTextStream in (&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void notes::on_actionSave_triggered()
{

    QFile file (file_path);
    if (!file.open(QFile :: WriteOnly|QFile ::Text))
    {
        QMessageBox::warning (this,"..","file not open");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();


}


void notes::on_actionSave_as_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"open the file");
    QFile file (file_name);
    file_path=file_name;
    if (!file.open(QFile :: WriteOnly|QFile ::Text))
    {
        QMessageBox::warning (this,"..","file not open");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void notes::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void notes::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void notes::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void notes::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void notes::on_actionUndo_triggered()
{   ui->textEdit->undo();

}


void notes::on_actionAbout_Notepad_triggered()
{

}


void notes::on_actionClose_triggered()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


