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
    ui->lineEdit_stock->clear();
}

//go left,go right
// ui->name->settext(item[index].name)
// index --
// if(index = 0) cant go left

// item[index] = ui->lineedit.name->text()

void adminmanageitems::on_pushButton_left_clicked()
{
    if (index > 0) {
        //ui->lineEdit_name->setText(center->getitems()[index].getname());
        index--;
        updateItemUI();
    } else {
        QMessageBox::warning(this, "Error", "Already at the first item.");
    }
}


void adminmanageitems::on_pushButton_right_clicked()
{
    if (index < center->getitems().size() - 1) {
        index++; // Move to the next item
        updateItemUI(); // Update the UI
    } else {
        QMessageBox::warning(this, "Error", "Already at the last item.");
    }
}

void adminmanageitems::on_pushButton_name_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp);
    ui->label_name->setText(temp);
}

void adminmanageitems::on_pushButton_price_clicked()
{
    QString temp = ui->lineEdit_price->text();
    center->getitems()[index].updateprice(temp.toDouble());
    updateItemUI();
}


void adminmanageitems::on_pushButton_description_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp);
    ui->label_name->setText(temp);
}

void adminmanageitems::on_pushButton_availability_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp);
    ui->label_name->setText(temp);
}


void adminmanageitems::on_pushButton_stock_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp);
    ui->label_name->setText(temp);
}


void adminmanageitems::on_pushButton_period_clicked()
{
    QString temp = ui->lineEdit_name->text();
    center->getitems()[index].updatename(temp);
    ui->label_name->setText(temp);
}


void adminmanageitems::on_pushButton_add_clicked()
{

}


void adminmanageitems::on_pushButton_delete_clicked()
{

}

void adminmanageitems::updateItemUI()
{
    const item &currentItem = center->getitems()[index];
    ui->lineEdit_name->setText(currentItem.getname());
    ui->lineEdit_price->setText(QString::number(currentItem.getprice()));
    ui->lineEdit_description->setText(currentItem.getdescription());
    ui->lineEdit_availability->setText(currentItem.isavailable() ? "Available" : "Unavailable");
    ui->lineEdit_stock->setText(QString::number(currentItem.getstock()));
    ui->lineEdit_period->setText(QString::number(currentItem.getrentalperiod()));
}
