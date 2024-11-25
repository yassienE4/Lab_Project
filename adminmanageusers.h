#ifndef ADMINMANAGEUSERS_H
#define ADMINMANAGEUSERS_H

#include <QDialog>
#include <vector>
#include "centerflow.h"
#include "users.h"

namespace Ui {
class adminmanageusers;
}


class adminmanageusers : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanageusers(QWidget *parent=nullptr, centerflow* center = nullptr);
    ~adminmanageusers() ;


private slots:
    void displayUsers() ;
    void on_pushButton_LoadUsers_clicked();
    void on_pushButton_DeleteUser_clicked();
    void on_pushButton_Back_clicked();

private:
    Ui::adminmanageusers *ui;
    centerflow *center;
    void populateTable(const vector<users>& users);
};

#endif
