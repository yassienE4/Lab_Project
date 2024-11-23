#include "centerflow.h"
#include "mainwindow.h"
#include "allaccounts.h"
#include <QList>
#include <fstream>
#include "users.h"
#include "admin.h"

centerflow::centerflow()
{
    MainWindow w;
    w.show();
    QList<allaccounts> *accounts;
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
            allaccounts *temp;
            t = temp;
            getline(myfile,temp.account.name);
            getline(myfile,temp.password);
            accounts.push_back(t);
        }
        myfile.close();
}
