#include "adminmanageitems.h"
#include "ui_adminmanageitems.h"

adminmanageitems::adminmanageitems(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::adminmanageitems), center(center)
{
    ui->setupUi(this);
}

adminmanageitems::~adminmanageitems()
{
    delete ui;
}

void adminmanageitems::on_pushButton_Clear_clicked()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_availability->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_description->clear();
    ui->lineEdit_period->clear();
    ui->lineEdit_rental->clear();
    ui->lineEdit_stock->clear();

}

//go left,go right
// ui->name->settext(item[index].name)
// index --
// if(index = 0) cant go left

// item[index] = ui->lineedit.name->text()


void adminmanageitems::on_pushButton_name_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp); // instead of 0 index
    ui->label_name->setText(temp);
}



void adminmanageitems::on_pushButton_left_clicked()
{
    if (index > 0) {
        //ui->name->settext(item[index].name)
        index--;
        //function to update ui?
    } else {
        QMessageBox::warning(this, "Error", "Already at the first item.");
    }
}


void adminmanageitems::on_pushButton_right_clicked()
{
    //ui->name->settext(item[index].name)
    index++;
}


