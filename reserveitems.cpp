#include "reserveitems.h"
#include "ui_reserveitems.h"
#include <QMessageBox>
#include <centerflow.h>

reserveitems::reserveitems(QWidget *parent,centerflow *center)
    : QDialog(parent)
    , ui(new Ui::reserveitems), center(center)
{
    ui->setupUi(this);
}

reserveitems::~reserveitems()
{
    delete ui;
}
void reserveitems::setItemDetails(const QString &name, const QString &description, int stock, double price, const item &item)
{
    ui->lineEditItemname->setText(name); // Set item name
    ui->lineEditDescription->setText(description); // Set item description
    ui->lineEditStock->setText(QString::number(stock) + " left in stock"); // Set stock
    ui->lineEditPrice->setText(QString::number(price, 'f', 2) + " USD price"); // Set price fixed-point notation.

    currentItem = item;
}

void reserveitems::addRentalRequest(const QString &itemName)
{
    for (const auto &item : center->getitems()) // Iterate through the vector to find the item
    {
        if (item->getname() == itemName)
        {
            // Add the item to rentalRequests instead of reserving it right away
            center->getrentalRequest().push_back(&item);  // Add item to rentalRequests vector

            QString message = "'" + itemName + "' has been added to your rental requests.";
            QMessageBox::information(this, "Item Added", message);
            return; // Exit the function after adding the item to the rental requests
        }
    }

    // If the item is not found
    QString message = "Item not found: " + itemName;
    QMessageBox::warning(this, "Error", message);
}

void reserveitems::on_pushButton1weekReserve_clicked()
{
    // Get the item name from the line edit where it's displayed
    QString itemName = ui->lineEditItemname->text();

    // Call addRentalRequest to add the item to rental requests
    addRentalRequest(itemName);
    currentItem.setrentalperiod(7);
}


void reserveitems::on_pushButton2weekReserve_clicked()
{
    // Get the item name from the line edit where it's displayed
    QString itemName = ui->lineEditItemname->text();

    // Call addRentalRequest to add the item to rental requests
    addRentalRequest(itemName);
    currentItem.setrentalperiod(14);
}


void reserveitems::on_pushButton3weekReserve_clicked()
{
    // Get the item name from the line edit where it's displayed
    QString itemName = ui->lineEditItemname->text();

    // Call addRentalRequest to add the item to rental requests
    addRentalRequest(itemName);
    currentItem.setrentalperiod(21);
}

