#include "userviewreservations.h"
#include "ui_userviewreservations.h"

userviewreservations::userviewreservations(QWidget *parent, centerflow* center)
    : QDialog(parent)
    , ui(new Ui::userviewreservations), center(center)
{
    ui->setupUi(this);
}

userviewreservations::~userviewreservations()
{
    delete ui;
}
void userviewreservations::loadConfirmedRentals(const vector<item> &confirmedrentals)
{
    populateReservations(confirmedrentals);
}

void userviewreservations::populateReservations(const vector<item> &confirmedrentals)
{
    ui->tableWidgetReservations->clear();

    for (const auto &rental : confirmedrentals) {
       // ui->tableWidgetReservations->addItem(QString::fromStdString(confirmedrentals.toString()));
    }
}
