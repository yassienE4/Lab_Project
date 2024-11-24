#include "allaccounts.h"
#include <fstream>
#include "users.h"
allaccounts::allaccounts()
{

}
allaccounts::allaccounts(QString x, QString y, QString z, QString w, QString v)
{
     email = x;
     name = y;
     username = z;
     contactinfo = w;
     password = v;
}
QString allaccounts::getemail()
{
    return email;
}
QString allaccounts::getname()
{
    return name;
}
QString allaccounts::getusername()
{
    return username;
}
QString allaccounts::getpassword()
{
    return password;
}

void allaccounts::setname(QString x)
{
    name = x;
}

void allaccounts::setpassword(QString x)
{
    password = x;
}

void allaccounts::setemail(QString x)
{
    email = x;
}
