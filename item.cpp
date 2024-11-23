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

bool item::isavailable() {
    return available;
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

vector<pair<int, item>> Qlist;
void removeitem(const item& x) {
    auto it = Qlist.begin();
    while (it != Qlist.end()) {
        if (it->second == x) {
            it = Qlist.erase(it);
        } else {
            ++it;
        }
    }
}
