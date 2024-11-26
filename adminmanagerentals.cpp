#include "adminmanagerentals.h"
#include "ui_adminmanagerentals.h"

adminmanagerentals::adminmanagerentals(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::adminmanagerentals), center(center)
{
    ui->setupUi(this);
}

adminmanagerentals::~adminmanagerentals()
{
    delete ui;
}

//in the new ui .cpp .h
//in the new ui you have two buttons
//accept= stock -1



void adminmanagerentals::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    this->hide();
    ApproveDeny *ap= new ApproveDeny(nullptr, center);
    ap->show();

}

