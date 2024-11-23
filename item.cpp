#include "item.h"
#include <string>
using namespace std;
item::item() {
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
