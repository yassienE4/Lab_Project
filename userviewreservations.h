#ifndef USERVIEWRESERVATIONS_H
#define USERVIEWRESERVATIONS_H

#include <QDialog>

namespace Ui {
class userviewreservations;
}

class userviewreservations : public QDialog
{
    Q_OBJECT

public:
    explicit userviewreservations(QWidget *parent = nullptr);
    ~userviewreservations();

private:
    Ui::userviewreservations *ui;
};

#endif // USERVIEWRESERVATIONS_H
