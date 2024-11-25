#ifndef APPROVEDENY_H
#define APPROVEDENY_H
#include "item.h"
#include "centerflow.h"
#include <QDialog>

namespace Ui {
class ApproveDeny;
}

class ApproveDeny : public QDialog
{
    Q_OBJECT

public:
    explicit ApproveDeny(QWidget *parent = nullptr, centerflow *center = nullptr);
    ~ApproveDeny();
    void setRentalDetails(item *rental);

private slots:
    void on_pushButtonApprove_clicked();

private:
    Ui::ApproveDeny *ui;
    item *currentRental;
    centerflow *center;

};

#endif // APPROVEDENY_H
