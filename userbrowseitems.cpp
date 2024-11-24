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


void userbrowseitems::searchItems()
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

       // create a string to display in the next step
        QString itemText = item.getName() + ": " + QString::number(item.getPrice()) + " USD [" + QString::number(item.getStock()) + " in stock]";


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
    void userbrowseitems::onItemClicked(QListWidgetItem *selectedItem)
    {
        QString itemText = selectedItem->text(); // Get the text of the selected item

        // Extract the item name
        QString itemName = itemText.split(":").first().trimmed();

        // Reserve the item
        reserveItem(itemName);
    }
}
void userbrowseitems::reserveItem(const QString &itemName)
{
    {
        for (Item &item : items) // Iterate through the vector to find the item
        {
            if (item.getName() == itemName)
            {
                if (item.isAvailable()) // Check if the item is available
                {
                    item.setStock(item.getStock() - 1); // Decrement stock
                    QString message = "You have successfully reserved '" + itemName + "'.";
                    QMessageBox::information(this, "Reservation Successful", message);

                    // refresh ui after reservation is successful
                    searchItems();
                }
                else
                {
                    QString message = "'" + itemName + "' is out of stock.";
                    QMessageBox::warning(this, "Reservation Failed", message);
                }
                return; // Exit the function after processing the item
            }
        }

        // If the item is not found
        QString message = "Item not found: " + itemName;
        QMessageBox::warning(this, "Error", message);
    }
}
