#ifndef ITEM_H
#define ITEM_H
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
    item(QString name, double price, int demand, QString description = "", bool available = true, int rentalPeriod = 0, int stock = 0); //
    bool isavailable() const;
    void updateprice(double Update);
    void updatepricedemand(double m);
    void updatename(const QString& Nn);
    void updatedescription(const QString& Nd);
    void updaterental(int ur);
    void updateavailability(bool Av);
    void updatestock(int s);
    void printItem();
    void removeItem(vector<item> &items, const QString &itemName);
    bool operator==(const item& other);
    void setname(QString x);
    void setprice(double x);
    void setdemand(int x);
    int getstock() const;
    QString getname() const;
    QString getdescription() const;
    double getprice() const;
    int getdemand();
    int getrentalperiod() const;
    void setstock(int x);
    void setrentalperiod(int x);
};

#endif // ITEM_H
