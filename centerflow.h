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

   //QVector<pair<int,item>> *items;
    vector<item> items;
    vector<item> rentalRequests;
    vector<item> confirmedrentals;
public:
    centerflow();
    ~centerflow();
    vector<users> normalUsers;
    vector<admin> adminUser;
    void pushuser(users x);
    void pushadmin(admin x);
    void pushrequest(item x);
    void eraserequest(); // needs paramter
    void pushitem(item x);
    vector<users> getvectoruser();
    vector<admin> getadminvector();
    vector<item> getrentalRequest();
    vector<item> &getitems();
    vector<item> getconfirmedrentals();

    bool getuserwithname(QString username,QString password);
};

#endif // CENTERFLOW_H
