#include "adminmanageitems.h"
#include "ui_adminmanageitems.h"

adminmanageitems::adminmanageitems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminmanageitems)
{
    ui->setupUi(this);
}

adminmanageitems::~adminmanageitems()
{
    delete ui;
}
