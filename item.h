#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QMessageBox>
#include <QString>
using namespace std;
class item
{
private:
    QString name;
    double price;
    int stock;
    int demand;
    QString description;
    bool available;
    int rentalPeriod;
public:
    item();
    item(QString name, double price, int demand, QString description = "", bool available = true, int rentalPeriod = 0);
    bool isavailable();
    void updateprice(double Update);
    void updatepricedemand(double m);
    void updatename(const QString& Nn);
    void updatedescription(const QString& Nd);
    void updaterental(int ur);
    void updateavailability(bool Av);
    void printItem();
    void removeItem(vector<item> &items, const QString &itemName);
    bool operator==(const item& other);
    void setname(QString x);
    void setprice(double x);
    void setdemand(int x);
    int getstock();
    QString getname();
    QString getdescription();
    double getprice();
    int getdemand();
    int getrentalperiod();
    void setstock(int x);
};

#endif // ITEM_H
