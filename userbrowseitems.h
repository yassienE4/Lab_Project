#ifndef USERBROWSEITEMS_H
#define USERBROWSEITEMS_H

#include <QDialog>
#include <QVector>
#include <vector>
#include "item.h"
#include <QListWidgetItem>
#include "centerflow.h"

namespace Ui {
class userbrowseitems;
}

class userbrowseitems : public QDialog
{
    Q_OBJECT

public:
    explicit userbrowseitems(QWidget *parent = nullptr);
    ~userbrowseitems();

private slots:
    void on_MinPriceSpinBox_textChanged(const QString &arg1);

    void on_pushButtonSearch_clicked();

    void on_listWidget_results_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::userbrowseitems *ui;
    vector<item> *items;
    vector<item> *rentalRequests;  // Vector to hold reserved items (rental requests)

    void searchItems();
    //void reserveItem(const QString &itemName);
    void addRentalRequest(const QString &itemName);
};

#endif // USERBROWSEITEMS_H
