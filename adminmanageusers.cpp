#include "adminmanageusers.h"
#include "ui_adminmanageusers.h"
#include <QMessageBox>
#include <QListWidgetItem>
<<<<<<< Updated upstream
=======
using namespace std;

>>>>>>> Stashed changes

AdminManageUsers::AdminManageUsers(QWidget *parent, centerflow* center) :
    QDialog(parent),
    ui(new Ui::AdminManageUsers) ,
    center (center)
{
    ui-> setupUi (this);
}

AdminManageUsers::~AdminManageUsers()
{
    delete ui ;
}

void AdminManageUsers::populateTable(const vector<users>& users) {
    QTableWidget* table = ui->userTable;
    table->setRowCount(center->getvectoruser().size());

    // Populate table with user data
    for (int row = 0; row < center->getvectoruser().size(); ++row) {
        const users& users = users[row];

        table->setItem(row, 0, new QTableWidgetItem(users.getemail));
        table->setItem(row, 1, new QTableWidgetItem(users.getname));
        table->setItem(row, 2, new QTableWidgetItem(users.getusername));
        table->setItem(row, 3, new QTableWidgetItem(users.getcontactInfo));
        table->setItem(row, 4, new QTableWidgetItem(users.getpassword));
    }
}

void AdminManageUsers::on_pushButton_LoadUsers_clicked()
{
    displayUsers() ;
}

void AdminManageUsers::on_pushButton_DeleteUser_clicked()
{
    QListWidgetItem*selectedItem=ui->listWidget_Users->currentItem();

    if (!selectedItem)
    {
        QMessageBox::warning(this,"No Selection","Please select a user to delete.");
        return;
    }

    QString selectedUserInfo= selectedItem->text();
    QString username=selectedUserInfo.split(" - ").first();// Extract username

    // Search for the user in the vector and remove
    vector<users>& usersVector = center->getvectoruser();
    auto it = remove_if(usersVector.begin(), usersVector.end(),
                             [username](const users& user) {
                                 return user.getname() == username;
                             });

    if (it != usersVector.end())
    {
        usersVector.erase(it,usersVector.end());
        QMessageBox::information(this,"Success","User deleted successfully.");
        displayUsers();
    }
    else
    {
        QMessageBox::warning(this,"Error","User not found.");
    }
}

void AdminManageUsers::on_pushButton_Back_clicked()
{
    this->hide() ;
    // Return to admin main page or previous window
}
