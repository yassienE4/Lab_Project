#ifndef USERS_H
#define USERS_H
#include "allaccounts.h"
#include "item.h"

class users : public allaccounts
{
public:
    users();
    void login();
    vector<item> CurrentReservations;
    vector<item> history;
};


#endif // USERS_H
