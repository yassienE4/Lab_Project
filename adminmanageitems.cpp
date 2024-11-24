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


