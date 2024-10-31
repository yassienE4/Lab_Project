#include "adminmanageusers.h"
#include "ui_adminmanageusers.h"

adminmanageusers::adminmanageusers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminmanageusers)
{
    ui->setupUi(this);
}

adminmanageusers::~adminmanageusers()
{
    delete ui;
}
