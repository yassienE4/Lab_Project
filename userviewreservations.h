#ifndef USERVIEWRESERVATIONS_H
#define USERVIEWRESERVATIONS_H
#include "users.h"
#include "centerflow.h"
#include <QDialog>

namespace Ui {
class userviewreservations;
}

class userviewreservations : public QDialog
{
    Q_OBJECT

public:
    explicit userviewreservations(QWidget *parent = nullptr, centerflow* center = nullptr);
    ~userviewreservations();

private:
    Ui::userviewreservations *ui;
    void populateReservations(const std::vector<item> &confirmedrentals);
    void loadConfirmedRentals(const std::vector<item> &confirmedrentals);
    centerflow* center;
};

#endif // USERVIEWRESERVATIONS_H
