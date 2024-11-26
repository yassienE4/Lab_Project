#include "adminmanagerentals.h"
#include "ui_adminmanagerentals.h"
#include "approvedeny.h" // For handling approve/deny dialog

adminmanagerentals::adminmanagerentals(QWidget *parent, centerflow *center)
    : QDialog(parent)
    , ui(new Ui::adminmanagerentals)
    , center(center)
{
    ui->setupUi(this);
    updateRentalUI();
}

adminmanagerentals::~adminmanagerentals()
{
    delete ui;
}


void adminmanagerentals::on_pushButton_clear_clicked()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_period->clear();
    ui->lineEdit_stock->clear();
}

void adminmanagerentals::on_tableWidget_itemDoubleClicked(QListWidgetItem* item) {

}


void adminmanagerentals::on_pushButton_left_clicked()
{
    if (index > 0) {
        index--;
        updateRentalUI();
    } else {
        QMessageBox::warning(this,"Error","Already at the first rental");
    }
}






void adminmanagerentals::on_pushButton_right_clicked()
{
    if (index < static_cast<int>(center->getitems().size()) - 1) {
        index++;
        updateRentalUI();
    } else {
        QMessageBox::warning(this, "Error", "Already at the last rental.");
    }
}


void adminmanagerentals::on_pushButton_openApproveDeny_clicked()
{
    if (center->getitems().empty()) {
        QMessageBox::warning(this, "No Rentals", "There are no rentals to approve or deny.");
        return;
    }

    item *currentRental = center->getitems()[index];
    if (!currentRental) {
        QMessageBox::warning(this, "Error", "No rental selected.");
        return;
    }

    // Open the ApproveDeny dialog
    ApproveDeny approveDenyDialog(this, center, nullptr); // Replace nullptr with the appropriate user object if available
    approveDenyDialog.setRentalDetails(currentRental);
    approveDenyDialog.exec();

    updateRentalUI();
}

void adminmanagerentals::updateRentalUI()
{
    if (center->getitems().empty()) {
        ui->lineEdit_name->setText("No Rentals Available");
        ui->lineEdit_price->clear();
        ui->lineEdit_period->clear();
        ui->lineEdit_stock->clear();
        return;
    }

    const item &currentRental = *(center->getitems()[index]);
    ui->lineEdit_name->setText(currentRental.getname());
    ui->lineEdit_price->setText(QString::number(currentRental.getprice(), 'f', 2) + " USD");
    ui->lineEdit_period->setText(QString::number(currentRental.getrentalperiod()) + " days");
    ui->lineEdit_stock->setText(QString::number(currentRental.getstock()));
}
