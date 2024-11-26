#include "userviewrentalhistory.h"
#include "ui_userviewrentalhistory.h"

userviewrentalhistory::userviewrentalhistory(QWidget *parent, centerflow* center)
    : QDialog(parent)
    , ui(new Ui::userviewrentalhistory), center(center)
{
    ui->setupUi(this);
}

userviewrentalhistory::~userviewrentalhistory()
{
    delete ui;
}
