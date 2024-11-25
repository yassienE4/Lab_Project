#ifndef ADMINMANAGEUSERS_H
#define ADMINMANAGEUSERS_H

#include <QDialog>
#include <vector>
#include "centerflow.h"
#include "users.h"

namespace Ui {
class AdminManageUsers;
}


class AdminManageUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AdminManageUsers(QWidget *parent=nullptr, centerflow* center = nullptr);
    ~AdminManageUsers() ;


private slots:
    void displayUsers() ;
    void on_pushButton_LoadUsers_clicked();
    void on_pushButton_DeleteUser_clicked();
    void on_pushButton_Back_clicked();

private:
    Ui::AdminManageUsers *ui;
    centerflow *center;
    void populateTable(const vector<users>& users);
};

#endif
