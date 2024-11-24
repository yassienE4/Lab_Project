#include "adminmanagerentals.h"
#include "ui_adminmanagerentals.h"

adminmanagerentals::adminmanagerentals(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminmanagerentals)
{
    ui->setupUi(this);
}

adminmanagerentals::~adminmanagerentals()
{
    delete ui;
}

void adminmanagerentals::on_listWidgetRentalRequest_itemDoubleClicked(QListWidgetItem *item)
{
    this->hide();



}

//in the new ui .cpp .h
//in the new ui you have two buttons
//accept= stock -1
