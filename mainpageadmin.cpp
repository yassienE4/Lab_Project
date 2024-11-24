#include "mainpageadmin.h"
#include "ui_mainpageadmin.h"

mainpageadmin::mainpageadmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainpageadmin)
{
    ui->setupUi(this);
}

mainpageadmin::~mainpageadmin()
{
    delete ui;
}

void mainpageadmin::on_pushButton_item_clicked()
{

}


void mainpageadmin::on_pushButton_Rental_clicked()
{

}


void mainpageadmin::on_pushButton_user_clicked()
{

}

