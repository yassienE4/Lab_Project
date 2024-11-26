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
    void on_pushButton_clearFilter_clicked();
    void on_pushButton_openApproveDeny_clicked();
    void on_listWidget_rentals_itemClicked(QListWidgetItem *item);

    void on_pushButton_clear_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

private:
    Ui::adminmanagerentals *ui;
    centerflow *center;
    int index=0;

    void updateRentalUI();
};

#endif // ADMINMANAGERENTALS_H
