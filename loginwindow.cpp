#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
//#include "usermainpage.h"
//#include "adminmainpage.h"
#include <QDebug>
#include "users.h"

loginwindow::loginwindow(QWidget *parent, centerflow* center)
    : QDialog(parent)
    , ui(new Ui::loginwindow), center(center)
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
        vector<users>::iterator it = center->getvectoruser().begin(); //creates an iterator and places it at begining of vector
        while (it != center->getvectoruser().end()) //transverses vector until username and password is found or vector is fully transversed
        {
            if ((it->getusername() == username) && (it->getpassword() == password))
            {
                ui->Labelinvalid->setVisible(false); // Hide the error message (labelinvalid)

                this->hide();

                //usermainpage *UMP= new usermainpage();
                //UMP->show();
                return;
            }
            ++it;
        }

        ui->Labelinvalid->setVisible(true); // show the error message
        // check if username and passwords exist in vector(normalusers)
        //call normaluser function esmo openusermainpage = show the usermainpage
    }
    else
    {
        if(ui->lineEdit_adminkey->text() == "123")// admin key
        {

            vector<admin>::iterator it = center->getadminvector().begin();
            while (it != center->getadminvector().end())
            {
                if ((it->getusername() == username) && (it->getpassword() == password))
                {
                    ui->Labelinvalid->setVisible(false); // Hide the error message

                    this->hide();

                    //adminmainpage *AMP = new adminmainpage();
                    //AMP->show();
                    return;
                }
                ++it;
            }

            ui->Labelinvalid->setVisible(true); // show the error message
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
    MainWindow *m = new MainWindow(nullptr, center);
    m->show();
}

