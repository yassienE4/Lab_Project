#include "userbrowseitems.h"
#include "ui_userbrowseitems.h"

userbrowseitems::userbrowseitems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userbrowseitems)
{
    ui->setupUi(this);
}

userbrowseitems::~userbrowseitems()
{
    delete ui;
}
