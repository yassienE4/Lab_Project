#ifndef CENTERFLOW_H
#define CENTERFLOW_H
#include "allaccounts.h"
#include "users.h"
#include "admin.h"
#include "item.h"
#include <vector>
#include <QList>
class centerflow
{
private:
    int size;
    int adminsize;
    int itemsize;
    vector<users> normalUsers;
    vector<admin> adminUser;
   //QVector<pair<int,item>> *items;
    vector<item> items;
    vector<item> rentalRequests;
public:
    centerflow();
    ~centerflow();
    void pushuser(users x);
    void pushadmin(admin x);
    void pushrequest(item x);
    void eraserequest(); // needs paramter
    vector<users> getvectoruser();
    vector<admin> getadminvector();
    vector<item> getrentalRequest();
};

#endif // CENTERFLOW_H
