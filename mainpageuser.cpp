#include "mainpageuser.h"
#include "ui_mainpageuser.h"

mainpageuser::mainpageuser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainpageuser)
{
    ui->setupUi(this);
}

mainpageuser::~mainpageuser()
{
    delete ui;
}

void mainpageuser::on_pushButton_Browse_clicked()
{

}

