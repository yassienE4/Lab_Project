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
    vector<users> *normalUsers;
    vector<admin> *adminUser;
   //QVector<pair<int,item>> *items;
    vector<item> *items;
    vector<item> *rentalRequests;
public:
    centerflow();
    ~centerflow();
};

#endif // CENTERFLOW_H
