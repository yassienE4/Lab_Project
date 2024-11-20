#include "adminmainpage.h"
#include "ui_adminmainpage.h"

adminlogin::adminlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminlogin)
{
    ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}
