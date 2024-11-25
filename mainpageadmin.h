#ifndef MAINPAGEADMIN_H
#define MAINPAGEADMIN_H

#include <QDialog>
#include "centerflow.h"

namespace Ui {
class mainpageadmin;
}

class mainpageadmin : public QDialog
{
    Q_OBJECT

public:
    explicit mainpageadmin(QWidget *parent = nullptr, centerflow *center = nullptr);
    ~mainpageadmin();

private slots:
    void on_pushButton_item_clicked();

    void on_pushButton_Rental_clicked();

    void on_pushButton_user_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::mainpageadmin *ui;
    centerflow *center;
};

#endif // MAINPAGEADMIN_H
