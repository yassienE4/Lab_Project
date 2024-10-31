#include "userviewreservations.h"
#include "ui_userviewreservations.h"

userviewreservations::userviewreservations(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userviewreservations)
{
    ui->setupUi(this);
}

userviewreservations::~userviewreservations()
{
    delete ui;
}
