#include "userviewrentalhistory.h"
#include "ui_userviewrentalhistory.h"

userviewrentalhistory::userviewrentalhistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userviewrentalhistory)
{
    ui->setupUi(this);
}

userviewrentalhistory::~userviewrentalhistory()
{
    delete ui;
}
