#include "adminmanageusers.h"
#include "ui_adminmanageusers.h"
#include <QMessageBox>
#include <QListWidgetItem>

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

void AdminManageUsers::displayUsers()
{
    ui->listWidget_Users-> clear() ;
    for(const users& user:center->getvectoruser())
    {
        QString userInf =user.getname()+ " - " + user.getemail() ;
        ui->listWidget_Users->addItem(userInf) ;
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
    std::vector<users>& usersVector = center->getvectoruser();
    auto it = std::remove_if(usersVector.begin(), usersVector.end(),
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
