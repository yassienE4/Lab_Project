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
    if (index < static_cast<int>(center->getitems().size()) - 1) {
        index++;
        updateItemUI();
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
    ui->label_price->setText(temp);
}

void adminmanageitems::on_pushButton_description_clicked()
{
    QString temp = ui->lineEdit_description->text();
    center->getitems()[index].updatedescription(temp);
    ui->label_description->setText(temp);
}

void adminmanageitems::on_pushButton_availability_clicked()
{
    bool available = ui->lineEdit_availability->text().toLower() == "available";
    center->getitems()[index].updateavailability(available);
    ui->label_availability->setText(available ? "Available" : "Unavailable");
}


void adminmanageitems::on_pushButton_stock_clicked()
{
    QString temp = ui->lineEdit_stock->text();
    center->getitems()[index].updatestock(temp.toInt());
    ui->label_stock->setText(temp);
}


void adminmanageitems::on_pushButton_period_clicked()
{
    QString temp = ui->lineEdit_period->text();
    center->getitems()[index].updaterental(temp.toInt());
    ui->label_period->setText(temp);
}


void adminmanageitems::on_pushButton_add_clicked()
{
    QString name = ui->lineEdit_name->text();
    double price = ui->lineEdit_price->text().toDouble();
    QString description = ui->lineEdit_description->text();
    bool available = ui->lineEdit_availability->text().toLower() == "available";
    int stock = ui->lineEdit_stock->text().toInt();
    int rentalPeriod = ui->lineEdit_period->text().toInt();
    item newItem(name, price, description, available, rentalPeriod, stock);
    center->getitems().push_back(newItem);
    QMessageBox::information(this, "Item Added", "The item has been added successfully.");
    updateItemUI();
}


void adminmanageitems::on_pushButton_delete_clicked()
{
    if (QMessageBox::question(this, "Delete Item", "Are you sure you want to delete this item?") == QMessageBox::Yes) {

        center->getitems().erase(center->getitems().begin() + index);
        if (index >= static_cast<int>(center->getitems().size())) {
            index = static_cast<int>(center->getitems().size()) - 1;
        }
        updateItemUI();
    }
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
