#ifndef CENTERFLOW_H
#define CENTERFLOW_H
#include "allaccounts.h"
#include "users.h"
#include "admin.h"
#include "item.h"
#include <QVector>
#include <QList>
class centerflow
{
private:
    int size;
    int adminsize;
    int itemsize;
    QVector<users> *normalUsers;
    QVector<admin> *adminUser;
    QVector<pair<int,item>> *items;
public:
    centerflow();
    ~centerflow();
};

#endif // CENTERFLOW_H
