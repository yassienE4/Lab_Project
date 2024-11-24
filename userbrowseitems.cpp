#include "userbrowseitems.h"
#include "ui_userbrowseitems.h"

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

void BrowseWindow::setItems(const QList<Item> &itemList)
{
    items = itemList; // Update the items list
}

userbrowseitems::searchItems()
{
    QString keyword = ui->lineEditKeyWord->text();
    double minPrice = ui->MinPriceSpinBox->value();
    double maxPrice = ui->MaxPriceSpinBox->value();
    bool showAvailableOnly = ui->checkBoxAvailable->isChecked();

    ui->listWidget_results->clear(); // Clear previous search results

    // Iterate through the QVector of items and filter based on the search criteria
    for (const item &i : *items)
    {
        // Check if the item matches the keyword (case insensitive search in name or description)
        if (!keyword.isEmpty() &&
            !i.getName().contains(keyword, Qt::CaseInsensitive) &&
            !i.getDescription().contains(keyword, Qt::CaseInsensitive))
        {
            continue; // Skip this item if it does not match the keyword
        }

        // Check if the item price is within the specified price range
        if (i.getPrice() < minPrice || i.getPrice() > maxPrice)
        {
            continue; // Skip this item if it does not match the price range
        }

        // Check if only available items are to be shown
        if (showAvailableOnly && !i.isAvailable())
        {
            continue; // Skip this item if it's not available
        }

       // create a string to display in the next step, Idk how to do it


        ui->listWidget_results->addItem(itemText); // Add the item to the QListWidget
    }

    // If no items matched the search criteria, display a message in the QListWidget
    if (ui->listWidget_results->count() == 0)
    {
        ui->listWidget_results->addItem("No items match your search criteria.");
    }
}

