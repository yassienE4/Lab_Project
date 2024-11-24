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

}

