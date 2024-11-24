#include "userbrowseitems.h"
#include "ui_userbrowseitems.h"
#include <QMessageBox>
#include "item.h"
#include <string>
userbrowseitems::userbrowseitems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userbrowseitems)
{
    ui->setupUi(this);
}

userbrowseitems::~userbrowseitems()
{
    delete ui;
}


void userbrowseitems::searchItems()
{
    QString keyword = ui->lineEditKeyWord->text();
    double minPrice = ui->MinPriceSpinBox->value();
    double maxPrice = ui->MaxPriceSpinBox->value();
    bool showAvailableOnly = ui->checkBoxAvailable->isChecked();

    ui->listWidget_results->clear(); // Clear previous search results

    // Iterate through the QVector of items and filter based on the search criteria

    for (auto i : *items)
    {
        // Check if the item matches the keyword (case insensitive search in name or description)
        if (!keyword.isEmpty() &&
            !i.getname().contains(keyword, Qt::CaseInsensitive) &&
            !i.getdescription().contains(keyword, Qt::CaseInsensitive))
        {
            continue; // Skip this item if it does not match the keyword
        }

        // Check if the item price is within the specified price range
        if (i.getprice() < minPrice || i.getprice() > maxPrice)
        {
            continue; // Skip this item if it does not match the price range
        }

        // Check if only available items are to be shown
        if (showAvailableOnly && !i.isavailable())
        {
            continue; // Skip this item if it's not available
        }

       // create a string to display in the next step
        QString itemText = i.getname() + ": " + QString::number(i.getprice()) + " USD [" + QString::number(i.getstock()) + " in stock]";


        ui->listWidget_results->addItem(itemText); // Add the item to the QListWidget
    }

    // If no items matched the search criteria, display a message in the QListWidget
    if (ui->listWidget_results->count() == 0)
    {
        ui->listWidget_results->addItem("No items match your search criteria.");
    }
}


void userbrowseitems::on_pushButtonSearch_clicked()
{
    searchItems();
}


void userbrowseitems::on_listWidget_results_itemDoubleClicked(QListWidgetItem *item)
{
    {
        QString itemText = item->text(); // Get the text of the selected item

        // Extract the item name
        QString itemName = itemText.split(":").first().trimmed();

        // Add the item to rental requests
        addRentalRequest(itemName);
    }
}
void userbrowseitems::addRentalRequest(const QString &itemName)
{
    for (auto item : *items) // Iterate through the vector to find the item
    {
        if (item.getname() == itemName)
        {
            // Add the item to rentalRequests instead of reserving it right away
            rentalRequests->push_back(item);  // Add item to rentalRequests vector

            QString message = "'" + itemName + "' has been added to your rental requests.";
            QMessageBox::information(this, "Item Added", message);
            return; // Exit the function after adding the item to the rental requests
        }
    }

    // If the item is not found
    QString message = "Item not found: " + itemName;
    QMessageBox::warning(this, "Error", message);
}
