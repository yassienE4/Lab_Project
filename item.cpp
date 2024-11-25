#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructor

item::item()
{
    name ="";
    price = 0;
    demand =0;
    description = "";
    available = 0;
    rentalPeriod = 0;
    stock = 0;
}
item::item(QString n, double p, int d, QString desc, bool a, int rp, int w) {
    name = n;
    price = p;
    demand = d;
    description = desc;
    available = a;
    rentalPeriod = rp;
    stock = w;
}

bool item::isavailable()
{
    return stock > 0; // Available only if stock is greater than 0
}

void item::updateprice(double newPrice) {
    price = newPrice;
}

void item::updatepricedemand(double multiplier) {
    price *= (1 + multiplier * demand);
}

void item::updatename(const QString& newName) {
    name = newName;
}

void item::updatedescription(const QString& newDescription) {
    description = newDescription;
}

void item::updaterental(int newRentalPeriod) {
    rentalPeriod = newRentalPeriod;
}

void item::updateavailability(bool isAvailable) {
    available = isAvailable;
}

void item::printItem() {
    cout << "Name: " << name.toStdString() << ", Price: " << price << ", Demand: " << demand
         << ", Description: " << description.toStdString() << ", Available: " << (available ? "Yes" : "No")
         << ", Rental Period: " << rentalPeriod << " days" << endl;
}

bool item::operator==(const item& other)  {
    return name == other.name && price == other.price && demand == other.demand;
}

/*
void item::removeItem(vector<item> &items, const QString &itemName)
{
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i].getname() == itemName)
        {
            // Remove the item from the vector
            items.erase[i];

            // Display a success message
            string message = "'" + itemName + "' has been removed.";
            QMessageBox::information(nullptr, "Item Removed", message);
            return;
        }
    }

    // If the item is not found
    string message = "Item not found: " + itemName;
    QMessageBox::warning(nullptr, "Error", message);
}
*/

void item::setname(QString x)
{
    name = x;
}
QString item::getname()
{
    return name;
}
void item::setprice(double x)
{
    price = x;
}
void item::setdemand(int x)
{
    demand = x;
}

QString item::getdescription()
{
    return description;
}
double item::getprice()
{
    return price;
}
int item::getdemand()
{
    return demand;
}
int item::getrentalperiod()
{
    return rentalPeriod;
}
void item::setrentalperiod(int x)
{
    rentalPeriod = x;
}

int item::getstock()
{
    return stock;
}
void item::setstock(int x)
{
    stock = x;
}
