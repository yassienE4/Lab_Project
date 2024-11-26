#ifndef ADMIN_H
#define ADMIN_H
#include "allaccounts.h"
class admin : public allaccounts
{
public:
    admin();
    admin(QString x, QString y, QString z, QString w, QString v);
    void login();
};

#endif // ADMIN_H
