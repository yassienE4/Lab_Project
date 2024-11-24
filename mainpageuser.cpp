#include "mainpageuser.h"
#include "ui_mainpageuser.h"

mainpageuser::mainpageuser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainpageuser)
{
    ui->setupUi(this);
}

mainpageuser::~mainpageuser()
{
    delete ui;
}

void mainpageuser::on_pushButton_Browse_clicked()
{

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

