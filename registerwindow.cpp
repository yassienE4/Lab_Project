#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"

registerwindow::registerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_pushButton_Register_clicked()
{
    if(ui->lineEdit_AdminKey->text() == "")
    {
        // register user
        // put info inside vector user
    }
    else
    {
        if(ui->lineEdit_AdminKey->text() == "123");
        {
            // register admin
            // put info inside vector admin
        }
    }
}


void registerwindow::on_pushButton_Clear_clicked()
{
    ui->lineEdit_AdminKey->setText("");
    ui->lineEdit_Email->setText("");
    ui->lineEdit_Password->setText("");
    ui->lineEdit_RepeatPassword->setText("");
    ui->lineEdit_username->setText("");
}


void registerwindow::on_pushButton_Back_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow();
    m->show();
}

