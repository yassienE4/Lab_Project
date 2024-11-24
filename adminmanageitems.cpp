#include "adminmanageitems.h"
#include "ui_adminmanageitems.h"

adminmanageitems::adminmanageitems(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::adminmanageitems), center(center)
{
    ui->setupUi(this);
    int index = 0;
}

adminmanageitems::~adminmanageitems()
{
    delete ui;
}

void adminmanageitems::on_pushButton_Clear_clicked()
{
    ui->label_availability->setText("");
    //for all labels
}

//go left,go right
// ui->name->settext(item[index].name)
// index --
// if(index = 0) cant go left

// item[index] = ui->lineedit.name->text()


void adminmanageitems::on_pushButton_name_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[0].updatename(temp); // instead of 0 index
    ui->label_name->setText(temp);
}

