#include "approvedeny.h"
#include "ui_approvedeny.h"


ApproveDeny::ApproveDeny(QWidget *parent, centerflow *center, users *user)
    : QDialog(parent)
    , ui(new Ui::ApproveDeny), center(center), user(user)
{
    ui->setupUi(this);
}

ApproveDeny::~ApproveDeny()
{
    delete ui;
}


void ApproveDeny::setRentalDetails(item *rental)
{
    currentRental = rental; // Store the rental pointer
    ui->lineEditName->setText("Item: " + rental->getname());
    ui->lineEditPrice->setText("Price: " + QString::number(rental->getprice(), 'f', 2) + " USD");
    ui->lineEditPeriod->setText("Duration: " + QString::number(rental->getrentalperiod()) + " days");
}
void ApproveDeny::on_pushButtonApprove_clicked()
{
    {
        if (currentRental) //checks to see its not null to avoid mistakes
        {
            QMessageBox::information(this, "Approval", "Rental approved for item: " + currentRental->getname());
            int newStock = currentRental->getstock() - 1; // Get current stock and subtract 1
            if(newStock <3)
                center->applydemand(*currentRental);
            currentRental->setstock(newStock);
            center->getconfirmedrentals().push_back(*currentRental);
            user->CurrentReservations.push_back(*currentRental);
        }
        this->hide();
    }
}
