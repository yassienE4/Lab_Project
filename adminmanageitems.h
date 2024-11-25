#ifndef ADMINMANAGEITEMS_H
#define ADMINMANAGEITEMS_H

#include <QDialog>
#include "centerflow.h"
namespace Ui {
class adminmanageitems;
}

class adminmanageitems : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanageitems(QWidget *parent = nullptr, centerflow *center = nullptr);
    ~adminmanageitems();

private slots:
    void on_pushButton_Clear_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_name_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_price_clicked();

    void on_pushButton_description_clicked();

    void on_pushButton_rental_clicked();

    void on_pushButton_availability_clicked();

    void on_pushButton_stock_clicked();

    void on_pushButton_period_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::adminmanageitems *ui;
    centerflow *center;
    int index = 0;
    void updateItemUI();
};

#endif // ADMINMANAGEITEMS_H
