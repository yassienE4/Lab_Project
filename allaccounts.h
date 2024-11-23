#ifndef ALLACCOUNTS_H
#define ALLACCOUNTS_H
#include <QString>
#include <QList>
using namespace std;
class allaccounts
{
private:
        string email;
        string name;
        string username;
        string contactinfo;
        string password;
        //bool admin;
public:
    allaccounts();
    allaccounts(string x, string y, string z, string w, string v);
    virtual void login() = 0;
};

#endif // ALLACCOUNTS_H
