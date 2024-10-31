#include "reserveitems.h"
#include "ui_reserveitems.h"

reserveitems::reserveitems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reserveitems)
{
    ui->setupUi(this);
}

reserveitems::~reserveitems()
{
    delete ui;
}
