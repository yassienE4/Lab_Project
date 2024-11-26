#ifndef USERVIEWRENTALHISTORY_H
#define USERVIEWRENTALHISTORY_H

#include <QDialog>

namespace Ui {
class userviewrentalhistory;
}

class userviewrentalhistory : public QDialog
{
    Q_OBJECT

public:
    explicit userviewrentalhistory(QWidget *parent = nullptr, centerflow* center);
    ~userviewrentalhistory();

private:
    Ui::userviewrentalhistory *ui;
};

#endif // USERVIEWRENTALHISTORY_H
