#include "usermainpage.h"
#include "ui_usermainpage.h"

usermainpage::usermainpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::usermainpage)
{
    ui->setupUi(this);
}

usermainpage::~usermainpage()
{
    delete ui;
}
