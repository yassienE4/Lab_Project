#include "adminmanageusers.h"
#include "allaccounts.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

AdminManageUsers::AdminManageUsers(QWidget*parent,centerflow *center)
    : QDialog(parent), center(center) {

    QVBoxLayout*mainLayout =new QVBoxLayout(this);

    QHBoxLayout*searchLayout = new QHBoxLayout();
    searchInput =new QLineEdit(this);
    searchButton= new QPushButton("Search",this);
    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchButton);
    mainLayout->addLayout(searchLayout);

    userTable= new QTableWidget(this);
    userTable->setColumnCount(4);
    userTable->setHorizontalHeaderLabels({"Username","Email","Name","Contact Info"});
    mainLayout->addWidget(userTable);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    usernameInput= new QLineEdit(this);
    emailInput =new QLineEdit(this);
    nameInput= new QLineEdit(this);
    contactInput= new QLineEdit(this) ;
    passwordInput = new QLineEdit(this) ;

    inputLayout->addWidget(usernameInput) ;
    inputLayout->addWidget(emailInput);
    inputLayout-> addWidget(nameInput) ;
    inputLayout->addWidget(contactInput);
    inputLayout->addWidget(passwordInput);
    mainLayout->addLayout(inputLayout);

    QHBoxLayout *buttonLayout =new QHBoxLayout();
    addButton =newQPushButton ("Add",this);
    editButton= new QPushButton("Edit", this);
    deleteButton =new QPushButton("Delete", this);

    buttonLayout->addWidget(addButton) ;
    buttonLayout->addWidget(editButton) ;
    buttonLayout->addWidget(deleteButton) ;
    mainLayout->addLayout(buttonLayout);

    connect(addButton,&QPushButton::clicked, this,&AdminManageUsers::addUser) ;
    connect(editButton,&QPushButton::clicked, this, &AdminManageUsers::editUser) ;
    connect(deleteButton, &QPushButton::clickedthis,&AdminManageUsers::deleteUser);
    connect(searchButton, &QPushButton::clicked, this,&AdminManageUsers::searchUser);

    loadUserTable();
}

void AdminManageUsers::loadUserTable() {
    userTable->setRowCount(0);  // Clear table
    for (const auto &user : center->getvectoruser()) {
        int row =userTable->rowCount();
        userTable->insertRow(row);
        userTable->setItem(row, 0,new QTableWidgetItem(user.getusername()));
        userTable->setItem(row,1,new QTableWidgetItem(user.getemail()));
        userTable->setItem(row,2, new QTableWidgetItem(user.getname()));

        allaccounts account ;
        account.setcontactinfo(user.getcontactinfo());
        userTable->setItem(row,3,new QTableWidgetItem(account.getcontactinfo()));
    }
}

void AdminManageUsers::addUser() {
    QString username =usernameInput->text().trimmed();
    QString email =emailInput->text().trimmed();
    QString name =nameInput->text().trimmed();
    QString contact =contactInput->text().trimmed();
    QString password =passwordInput->text().trimmed();

    if (username.isEmpty() || email.isEmpty() || name.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }


    for (const auto &user :center->getvectoruser()) {
        if (user.getusername()== username) {
            QMessageBox::warning(this, "Duplicate User", "Username already exists.");
            return;
        }
    }

    users newUser ;
    newUser.setname(username);
    newUser.setemail(email);
    newUser.setpassword(password) ;
    newUser.setcontactinfo(contact);

    center->pushuser(newUser);
    loadUserTable();
    QMessageBox::information(this, "Success", "User added successfully.");
}

void AdminManageUsers::editUser() {
    int row =userTable->currentRow();
    if (row==-1) {
        QMessageBox::warning(this, "Selection Error", "Please select a user to edit.");
        return;
    }

    QString username =usernameInput->text().trimmed();
    QString email =emailInput->text().trimmed() ;
    QString name= nameInput->text().trimmed();
    QString contact = contactInput->text().trimmed() ;
    QString password= passwordInput->text().trimmed();

    if (username.isEmpty()|| email.isEmpty() ||name.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error","Please fill in all fields.");
        return;
    }

    auto &usersVector =center->getvectoruser();
    users &userToEdit=usersVector[row];
    userToEdit.setname(username) ;
    userToEdit.setemail(email);
    userToEdit.setpassword(password) ;
    userToEdit.setcontactinfo(contact);

    loadUserTable();
    QMessageBox::information(this,"Success","User details updated successfully.");
}

void AdminManageUsers::deleteUser() {
    int row =userTable->currentRow();
    if (row ==-1) {
        QMessageBox::warning(this,"Selection Error","Please select a user to delete.");
        return;
    }

    QString username =userTable->item(row, 0)->text();
    if (QMessageBox::question(this, "Confirm Deletion","Delete user: " + username + "?",QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        auto &usersVector =center->getvectoruser();
        usersVector.erase(usersVector.begin() + row);
        loadUserTable() ;
        QMessageBox::information(this,"Success","User deleted successfully.");
    }
}

void AdminManageUsers::searchUser() {
    QString query=searchInput->text().trimmed();
    if (query.isEmpty()){
        loadUserTable() ;
        return ;
    }

    userTable->setRowCount(0);
    for (const auto &user: center->getvectoruser()) {
        if (user.getusername().contains(query, Qt::CaseInsensitive) ||
            user.getemail().contains(query, Qt::CaseInsensitive)) {
            int row= userTable->rowCount();
            userTable->insertRow(row);
            userTable->setItem(row,0,new QTableWidgetItem(user.getusername())) ;
            userTable->setItem(row,1,new QTableWidgetItem(user.getemail())) ;
            userTable->setItem(row, 2,new QTableWidgetItem(user.getname())) ;
            userTable->setItem(row, 3,new QTableWidgetItem(user.getcontactinfo()));
        }
    }

    if (userTable-> rowCount() ==0) {
        QMessageBox::information(this,"No Results","No users match your search criteria.") ;
    }
}
