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
