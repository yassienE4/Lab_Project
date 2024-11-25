#ifndef RESERVEITEMS_H
#define RESERVEITEMS_H

#include <QDialog>
#include "item.h"

namespace Ui {
class reserveitems;
}

class reserveitems : public QDialog
{
    Q_OBJECT

public:
    explicit reserveitems(QWidget *parent = nullptr);

    void setItemDetails(const QString &name, const QString &description, int stock, double price, const item &item);
    void addRentalRequest(const QString &itemName);
    ~reserveitems();

private slots:
    void on_pushButton1weekReserve_clicked();

    void on_pushButton2weekReserve_clicked();

    void on_pushButton3weekReserve_clicked();

private:
    Ui::reserveitems *ui;
    item currentItem; //item being reserved
   vector<item> *rentalRequests;  // Vector to hold reserved items (rental requests)
    vector<item> *items;


};

#endif // RESERVEITEMS_H
