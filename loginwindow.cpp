#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QDebug>

loginwindow::loginwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_pushButton_Login_clicked()
{
    if(ui->lineEdit_adminkey->text() == "") // check if admin is blank
    {
        //open user
    }
    else
    {
        if(ui->lineEdit_adminkey->text() == "123")// admin key
        {
            //open admin
        }
    }
}


void loginwindow::on_pushButton_Clear_clicked()
{
    ui->lineEdit_adminkey->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_username->setText("");

}


void loginwindow::on_pushButton_Back_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow();
    m->show();
}

