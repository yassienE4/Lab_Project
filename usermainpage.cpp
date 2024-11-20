#include "usermainpage.h"
#include "ui_usermainpage.h"

userlogin::userlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}
