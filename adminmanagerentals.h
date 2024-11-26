#ifndef ADMINMANAGERENTALS_H
#define ADMINMANAGERENTALS_H
#include <QListWidgetItem>
#include "centerflow.h"
#include "approvedeny.h"

#include <QDialog>

namespace Ui {
class adminmanagerentals;
}

class adminmanagerentals : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanagerentals(QWidget *parent = nullptr , centerflow *center = nullptr);
    ~adminmanagerentals();

private slots:


    void on_tableWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::adminmanagerentals *ui;
    centerflow *center;

};

#endif // ADMINMANAGERENTALS_H
