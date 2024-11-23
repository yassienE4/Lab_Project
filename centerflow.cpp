#include "centerflow.h"
#include "mainwindow.h"
#include "allaccounts.h"
#include <QList>
#include <fstream>
#include "users.h"
#include "admin.h"
#include <Qpair>
#include "item.h"

centerflow::centerflow()
{
    MainWindow w;
    w.show();
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
            t.setname(n);
            getline(myfile,n);
            t.setpassword(n);
            normalUsers->push_back(t);
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
            t.setname(n);
            getline(myfile,n);
            t.setpassword(n);
            adminUser->push_back(t);
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
            t.setname(a);
            getline(myfile,a);
            t.setprice(stod(a));
            getline(myfile,a);
            t.setdemand(stoi(a));
            getline(myfile,temp);
            pair<int, item> p = {stoi(temp), t};
            items->push_back(p);
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
            myfile<< normalUsers[i].getname() + "\n";
            myfile<< normalUsers[i].passwords + "\n";
        }
        myfile.close();
    }

    myfile.open(":/files/admin.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<to_string(adminsize) + "\n";
        for (int i = 0; i < adminsize; i++)
        {
            myfile<< adminUser[i].name + "\n";
            myfile<< adminUser[i].passwords + "\n";
        }
        myfile.close();
    }
    myfile.open(":/files/iteminventoryfile.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<to_string(itemsize) + "\n";
        for (int i = 0; i < itemsize; i++)
        {
            myfile<< items[i].second.name + "\n";
            myfile<< items[i].second.price + "\n";
            myfile<< items[i].second.demand + "\n";
            myfile<< items[i].first + "\n";
        }
        myfile.close();
    }

}
