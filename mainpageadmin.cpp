#include "mainpageadmin.h"
#include "ui_mainpageadmin.h"

#include "adminmanagerentals.h"
#include "adminmanageitems.h"
#include "mainwindow.h"


mainpageadmin::mainpageadmin(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::mainpageadmin), center(center)
{
    ui->setupUi(this);
}

mainpageadmin::~mainpageadmin()
{
    delete ui;
}

void mainpageadmin::on_pushButton_item_clicked()
{
    adminmanageitems * manageitem = new adminmanageitems(this,center);
    this->show();
    manageitem->show();

}


void mainpageadmin::on_pushButton_Rental_clicked()
{
    adminmanagerentals * managerental = new adminmanagerentals(this,center);
    this->show();
    managerental ->show();
}


void mainpageadmin::on_pushButton_user_clicked()
{

    // Create the AdminManageUsers dialog and pass the necessary data (like centerflow)
    //adminmanageusers* manageUsersPage = new adminmanageusers(this, center);
    //this->hide();
    // Show the dialog
    //manageUsersPage->show();
}


void mainpageadmin::on_pushButton_Back_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow(nullptr, center);
    m->show();
}


