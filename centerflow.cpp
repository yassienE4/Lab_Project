#include "centerflow.h"
#include "mainwindow.h"
#include "allaccounts.h"
#include <QList>
#include <fstream>
#include "users.h"
#include "admin.h"
#include <Qpair>
#include "item.h"
#include <QString>

centerflow::centerflow()
{
    QString p = "1";
    users x(p,p,p,p,p);
    normalUsers.push_back(x);
    fstream myfile;
    myfile.open(":/files/accountfile.txt",ios::in);
    if(myfile.is_open())
    {
        string tem;
        getline(myfile,tem);
        size = stoi(tem);
        for(int i = 0; i < size; i++)
        {
            users t;
            string n;
            getline(myfile,n);
            QString x = x.fromStdString(n);
            t.setname(x);
            getline(myfile,n);
            x = x.fromStdString(n);
            t.setpassword(x);
            normalUsers.push_back(t);
        }
        myfile.close();
    }


    //fstream myfile;
    myfile.open(":/files/admin.txt",ios::in);
    if(myfile.is_open())
    {
        string tem;
        getline(myfile,tem);
        adminsize = stoi(tem);
        for(int i = 0; i < adminsize; i++)
        {
            admin t;
            string n;

            getline(myfile,n);
            QString x = x.fromStdString(n);
            t.setname(x);
            getline(myfile,n);
            x = x.fromStdString(n);
            t.setpassword(x);
            adminUser.push_back(t);
        }
        myfile.close();
    }

    //fstream myfile;
    myfile.open(":/files/iteminventoryfile.txt",ios::in);
    if(myfile.is_open())
    {
        string tem;
        getline(myfile,tem);
        itemsize = stoi(tem);
        for(int i = 0; i < itemsize; i++)
        {
            item t;
            string temp;
            string a;
            getline(myfile,a);
            QString x = x.fromStdString(a);
            t.setname(x);
            getline(myfile,a);
            t.setprice(stod(a));
            getline(myfile,a);
            t.setdemand(stoi(a));
            getline(myfile,a);
            t.setstock(stoi(a));
            items.push_back(t);
        }
        myfile.close();
    }

}

centerflow::~centerflow()
{
    fstream myfile;
    myfile.open(":/files/accountfile.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<to_string(size) + "\n";
        for (int i = 0; i < size; i++)
        {
            myfile << normalUsers[i].getname().toStdString() + "\n";
            myfile << normalUsers[i].getpassword().toStdString() + "\n";
        }
        myfile.close();
    }

    myfile.open(":/files/admin.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<to_string(adminsize) + "\n";
        for (int i = 0; i < adminsize; i++)
        {
            myfile << adminUser[i].getname().toStdString() + "\n";
            myfile << adminUser[i].getpassword().toStdString() + "\n";
        }
        myfile.close();
    }
    myfile.open(":/files/iteminventoryfile.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<to_string(itemsize) + "\n";
        for (int i = 0; i < itemsize; i++)
        {
            myfile << items[i].getname().toStdString() + "\n";
            myfile<< to_string(items[i].getprice()) + "\n";
            myfile<< to_string(items[i].getdemand()) + "\n";
            myfile<< to_string(items[i].getstock()) + "\n";
        }
        myfile.close();
    }

}

void centerflow::pushuser(users x)
{
    normalUsers.push_back(x);
}
void centerflow::pushadmin(admin x)
{
    adminUser.push_back(x);
}
void centerflow::pushitem(item x)
{
    items.push_back(x);
}

vector<users> centerflow::getvectoruser() {
    qDebug() << "called2";
    return normalUsers;  // Ensure normalUsers is not a temporary object
}

vector<admin> centerflow::getadminvector()
{
    return adminUser;
}
void centerflow::pushrequest(item x)
{
    rentalRequests.push_back(x);
}
void centerflow::eraserequest()
{
    //rentalRequests.erase();
}
vector<item> centerflow::getrentalRequest()
{
    return rentalRequests;
}

vector<item> &centerflow::getitems()
{
    return items;
}
vector<item> centerflow::getconfirmedrentals()
{
    return confirmedrentals;

}

bool centerflow::getuserwithname(QString username, QString password)
{
    qDebug() << "called4";
}

