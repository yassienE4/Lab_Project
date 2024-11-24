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

private:
    Ui::adminmanageitems *ui;
    centerflow *center;
};

#endif // ADMINMANAGEITEMS_H
