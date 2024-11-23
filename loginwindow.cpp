#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "usermainpage.h"
#include "adminmainpage.h"
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
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(ui->lineEdit_adminkey->text().isEmpty()) // check if admin is blank
    {
        vector<NormalUser>::iterator it = normalUsers.begin(); //creates an iterator and places it at begining of vector
        while (it != normalUsers.end()) //transverses vector until username and password is found or vector is fully transversed
        {
            if ((it->username == username) && (it->password == password))
            {
                ui->labelinvalid->setVisible(false); // Hide the error message (labelinvalid)

                this->hide()

                usermainpage *UMP= new usermainpage();
                UMP->show();
                return;
            }
            ++it;
        }

        ui->labelinvalid->setVisible(true); // show the error message
        // check if username and passwords exist in vector(normalusers)
        //call normaluser function esmo openusermainpage = show the usermainpage
    }
    else
    {
        if(ui->lineEdit_adminkey->text() == "123")// admin key
        {

            vector<AdnminUser>::iterator it = adminUser.begin();
            while (it != adminUser.end())
            {
                if ((it->username == username) && (it->password == password))
                {
                    ui->labelinvalid->setVisible(false); // Hide the error message

                    this->hide()

                    adminmainpage *AMP = new adminmainpage();
                    AMP->show();
                    return;
                }
                    return;
                }
                ++it;
            }

            ui->labelinvalid->setVisible(true); // show the error message
            // check if username and passwords exist in vector(adminuser)
            //call adminuser function esmo openadminusermainpage = show the adminusermainpage
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

