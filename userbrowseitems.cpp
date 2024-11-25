#include "userbrowseitems.h"
#include "ui_userbrowseitems.h"
#include <QMessageBox>
#include "item.h"
#include <string>
#include <reserveitems.h>
#include "centerflow.h"
userbrowseitems::userbrowseitems(QWidget *parent,centerflow *center)
    : QDialog(parent)
    , ui(new Ui::userbrowseitems) , center(center)
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

    for (auto i :center->getitems())
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

        for (auto item :center->getitems()) // Iterate through the vector to find the item
        {
            if (item.getname() == itemName)
            {
                reserveitems *R= new reserveitems(this);
                R->setItemDetails(item.getname(),item.getdescription(),item.getstock(),item.getprice(),item);

                R->show();

                // Hide the current window
                this->hide();

                // Return after finding and processing the item
                return;
            }
        }

        // If the item is not found, show a warning
        QMessageBox::warning(this, "Error", "Item not found.");
    }
}
