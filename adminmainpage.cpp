#include "adminmainpage.h"
#include "ui_adminmainpage.h"

adminmainpage::adminmainpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminmainpage)
{
    ui->setupUi(this);
}

adminmainpage::~adminmainpage()
{
    delete ui;
}
