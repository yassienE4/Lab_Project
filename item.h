#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
class item
{
private:
    string name;
    double price;
    int demand;
    string description;
    bool available;
    int rentalPeriod;
public:
    item();
    item(string name, double price, int demand, string description = "", bool available = true, int rentalPeriod = 0);
    bool isavailable();
    void updateprice(double Update);
    void updatepricedemand(double m);
    void updatename(const string& Nn);
    void updatedescription(const string& Nd);
    void updaterental(int ur);
    void updateavailability(bool Av);
    void printItem();
    void removeItem(item x);
    bool operator==(const item& other);
    void setname(string x);
    void setprice(double x);
    void setdemand(int x);
};

#endif // ITEM_H
