#ifndef ADMINMANAGERENTALS_H
#define ADMINMANAGERENTALS_H
#include <QListWidgetItem>
#include "centerflow.h"

#include <QDialog>

namespace Ui {
class adminmanagerentals;
}

class adminmanagerentals : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanagerentals(QWidget *parent = nullptr);
    ~adminmanagerentals();

private slots:


private:
    Ui::adminmanagerentals *ui;
    centerflow *center;

};

#endif // ADMINMANAGERENTALS_H
