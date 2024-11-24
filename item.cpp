#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructor
item::item(string n, double p, int d, string desc, bool a, int rp) {
    name = n;
    price = p;
    demand = d;
    description = desc;
    available = a;
    rentalPeriod = rp;
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

void item::updatename(const string& newName) {
    name = newName;
}

void item::updatedescription(const string& newDescription) {
    description = newDescription;
}

void item::updaterental(int newRentalPeriod) {
    rentalPeriod = newRentalPeriod;
}

void item::updateavailability(bool isAvailable) {
    available = isAvailable;
}

void item::printItem() {
    cout << "Name: " << name << ", Price: " << price << ", Demand: " << demand
         << ", Description: " << description << ", Available: " << (available ? "Yes" : "No")
         << ", Rental Period: " << rentalPeriod << " days" << endl;
}

bool item::operator==(const item& other)  {
    return name == other.name && price == other.price && demand == other.demand;
}

void Item::removeItem(QVector<Item> &items, const QString &itemName)
{
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i].getName() == itemName)
        {
            // Remove the item from the vector
            items.remove(i);

            // Display a success message
            QString message = "'" + itemName + "' has been removed.";
            QMessageBox::information(nullptr, "Item Removed", message);
            return;
        }
    }

    // If the item is not found
    QString message = "Item not found: " + itemName;
    QMessageBox::warning(nullptr, "Error", message);
}

void item::setname(string x)
{
    name = x;
}
void item::setprice(double x)
{
    price = x;
}
void item::setdemand(int x)
{
    demand = x;
}
