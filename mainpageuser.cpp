#include "mainpageuser.h"
#include "ui_mainpageuser.h"
#include "userbrowseitems.h"
#include "userviewreservations.h"
#include "userviewrentalhistory.h"


mainpageuser::mainpageuser(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::mainpageuser), center(center)
{
    ui->setupUi(this);
}

mainpageuser::~mainpageuser()
{
    delete ui;
}

void mainpageuser::on_pushButton_Browse_clicked()
{
    userbrowseitems browse = new userbrowseitems(&parent, &center);
}


void mainpageuser::on_pushButton_Reserve_clicked()
{

}


void mainpageuser::on_pushButton_View_clicked()
{

}


void mainpageuser::on_pushButton_History_clicked()
{

}


void mainpageuser::on_pushButton_Back_clicked()
{

}

