#ifndef ADMINMANAGEUSERS_H
#define ADMINMANAGEUSERS_H

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include "centerflow.h"
#include "allaccounts.h"

class AdminManageUsers :public QDialog {
    Q_OBJECT

public:
    explicit AdminManageUsers(QWidget *parent =nullptr, centerflow *center = nullptr);
    ~AdminManageUsers();

private slots:
    void loadUserTable() ;
    void addUser() ;
    void editUser();
    void deleteUser();
    void searchUser();

private:
    QTableWidget *userTable;
    QLineEdit *searchInput;
    QLineEdit *usernameInput,*emailInput,*nameInput,*contactInput,*passwordInput;
    QPushButton *addButton, *editButton, *deleteButton, *searchButton;
    centerflow*center;
};

#endif // ADMINMANAGEUSERS_H
