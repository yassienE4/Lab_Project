#ifndef ALLACCOUNTS_H
#define ALLACCOUNTS_H
#include <QString>
#include <QList>
using namespace std;
class allaccounts
{
private:
        QString email;
        QString name;
        QString username;
        QString contactinfo;
        QString password;
        //bool admin;
public:
    allaccounts();
    allaccounts(QString x, QString y, QString z, QString w, QString v);
    QString getemail ();
    QString getname ();
    QString getusername();
    QString getpassword();
    void setname(QString x);
    void setpassword(QString x);
    void setemail(QString x);
    virtual void login() = 0;

    QString getcontactinfo() const { return contactinfo; }
    void setcontactinfo(const QString &info) { contactinfo = info; }

};

#endif // ALLACCOUNTS_H
