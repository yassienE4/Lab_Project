#ifndef ADMINMANAGERENTALS_H
#define ADMINMANAGERENTALS_H
#include <QListWidgetItem>


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
    void on_listWidgetRentalRequest_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::adminmanagerentals *ui;
};

#endif // ADMINMANAGERENTALS_H
