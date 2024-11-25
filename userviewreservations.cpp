#include "userviewreservations.h"
#include "ui_userviewreservations.h"

userviewreservations::userviewreservations(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userviewreservations)
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
