#include "allaccounts.h"
#include <fstream>
#include "users.h"
allaccounts::allaccounts()
{

}
allaccounts::allaccounts(string x, string y, string z, string w, string v)
{
     email = x;
     name = y;
     username = z;
     contactinfo = w;
     password = v;
}
string allaccounts::getemail()
{
    return email;
}
string allaccounts::getname()
{
    return name;
}
string allaccounts::getusername()
{
    return username;
}
string allaccounts::getpassword()
{
    return password;
}
