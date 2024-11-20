#ifndef ALLACCOUNTS_H
#define ALLACCOUNTS_H
#include <QString>
using namespace std;
class allusers
{
private:
    struct info
    {
        string id;
        string name;
        string username;
        string contactinfo;
    };
public:
    allusers();
    virtual void login() = 0;
};

#endif // ALLACCOUNTS_H
