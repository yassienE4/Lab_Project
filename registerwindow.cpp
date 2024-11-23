#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

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
    QString username = ui->lineEdit_username->text();
    QString email = ui->lineEdit_Email->text();
    QString password = ui->lineEdit_Password->text();
    QString repeatPassword = ui->lineEdit_RepeatPassword->text();

    if (password != repeatPassword)
    {
        ui->label_error->setVisible(true); // Show the error message
        return;
    }
    if(ui->lineEdit_AdminKey->text() == "") //if admin key is empty then it is user registering
    {
        users newUser; //new object type user
        newUser.username = username;
        newUser.email = email;        //sets info in line edits to their feilds
        newUser.password = password;

        normalUsers.push_back(newUser);// Add the new user to the normalUsers vector
        ui->label_error->setVisible(false); // Hide the error message

        QMessageBox::information(this, "Success", "User registered successfully! Returning to login page.");

        this->hide();

        loginwindow *l = new loginwindow;
        l->show();

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

