#ifndef APPROVEDENY_H
#define APPROVEDENY_H
#include "item.h"
#include "centerflow.h"
#include <QDialog>
#include "users.h"
namespace Ui {
class ApproveDeny;
}

class ApproveDeny : public QDialog
{
    Q_OBJECT

public:
    explicit ApproveDeny(QWidget *parent = nullptr, centerflow *center = nullptr, users* user=nullptr);
    ~ApproveDeny();
    void setRentalDetails(item *rental);

private slots:
    void on_pushButtonApprove_clicked();
    void on_pushButtonDeny_clicked();

private:
    Ui::ApproveDeny *ui;
    item *currentRental;
    centerflow *center;
    users *user;


};

#endif // APPROVEDENY_H
