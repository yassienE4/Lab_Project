#include "mainpageuser.h"
#include "ui_mainpageuser.h"
#include "userbrowseitems.h"
#include "userviewreservations.h"
#include "userviewrentalhistory.h"
#include "mainwindow.h"

mainpageuser::mainpageuser(QWidget *parent, centerflow * center,users *user)
    : QDialog(parent)
    , ui(new Ui::mainpageuser), center(center), user(user)
{
    ui->setupUi(this);
}

mainpageuser::~mainpageuser()
{
    delete ui;
}

void mainpageuser::on_pushButton_Browse_clicked()
{
    userbrowseitems *browse = new userbrowseitems(this, center);
    this->hide();
    browse->show();
}


void mainpageuser::on_pushButton_View_clicked()
{
    userviewreservations *view = new userviewreservations(this,center);
    this->hide();
    view->show();
}


void mainpageuser::on_pushButton_History_clicked()
{
    userviewrentalhistory *his = new userviewrentalhistory(this,center);
    this->hide();
    his->show();
}


void mainpageuser::on_pushButton_Back_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow(nullptr, center);
    m->show();
}

