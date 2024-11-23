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
    Qlist<users> *normalUsers;
    int size;
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
            getline(myfile,t.name);
            getline(myfile,t.password);
            normalUsers.push_back(t);
        }
        myfile.close();
    }

    Qlist<admin> *adminUser;
    int adminsize;
    fstream myfile;
    myfile.open(":/files/admin.txt",ios::in);
    if(myfile.is_open())
    {
        string tem;
        getline(myfile,tem);
        adminsize = stoi(tem);
        for(int i = 0; i < adminsize; i++)
        {
            admin t;
            getline(myfile,t.name);
            getline(myfile,t.password);
            adminUser.push_back(t);
        }
        myfile.close();
    }
    Qlist<pair<int,item> *items;
    int itemsize;
    fstream myfile;
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
            getline(myfile,t.name);
            getline(myfile,t.price);
            getline(myfile,t.demand);
            getline(myfile,temp);
            items.push_back(stoi(temp),t);
        }
        myfile.close();
    }

}

centerflow::~centerflow()
{
    myfile.open(":/files/accountfile.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<size + "\n";
        for (int i = 0; i < size; i++)
        {
            myfile<< normalUsers[i].name + "\n";
            myfile<< normalUsers[i].passwords + "\n";
        }
        myfile.close();
    }

    myfile.open(":/files/admin.txt",ios::out);

    if(myfile.is_open())
    {
        myfile<<adminsize + "\n";
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
        myfile<<itemsize + "\n";
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
