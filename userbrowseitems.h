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
    explicit userbrowseitems(QWidget *parent = nullptr, centerflow* center);
    ~userbrowseitems();

private slots:
    //void on_MinPriceSpinBox_textChanged(const QString &arg1);

    void on_pushButtonSearch_clicked();

    void on_listWidget_results_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::userbrowseitems *ui;
    centerflow *center;

    void searchItems();
};

#endif // USERBROWSEITEMS_H
