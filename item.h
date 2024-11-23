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
public:
    item();
    bool isavailable();
    void updateprice();
    void updatepricedemand();
    void updatename();
    void updatedescription();
    void updaterental();
    void updateavailability();
    void removeitem(item x);
};

#endif // ITEM_H
