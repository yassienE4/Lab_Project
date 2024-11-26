#include "userviewreservations.h"
#include "ui_userviewreservations.h"

userviewreservations::userviewreservations(QWidget *parent, centerflow* center)
    : QDialog(parent)
    , ui(new Ui::userviewreservations), center(center)
{
    ui->setupUi(this);
}

userviewreservations::~userviewreservations()
{
    delete ui;
}
void userviewreservations::populateList()
{
    ui->listWidgetReservations->clear(); // Clear any existing items

    // Iterate through the confirmed rentals vector and add each item to the QListWidget
    for (const auto &rental : center->getconfirmedrentals())
    {
        QString itemText = (rental.getname()) + ": price: " +QString::number(rental.getprice(), 'f', 2) + " USD, rental period: " +
                           QString::number(rental.getrentalperiod()) + " days";

        ui->listWidgetReservations->addItem(itemText); // Add the formatted text to the QListWidget
    }
}
