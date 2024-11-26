#include "adminmanageuser.h"
#include "ui_adminmanageuser.h"

adminmanageuser::adminmanageuser(QWidget *parent, centerflow *center)
    : QDialog(parent), ui(new Ui::adminmanageuser), center(center)
{
    ui->setupUi(this);
}

adminmanageuser::~adminmanageuser()
{
    delete ui;
}
