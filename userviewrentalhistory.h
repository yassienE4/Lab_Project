#ifndef USERVIEWRENTALHISTORY_H
#define USERVIEWRENTALHISTORY_H

#include <QDialog>
#include "centerflow.h"

namespace Ui {
class userviewrentalhistory;
}

class userviewrentalhistory : public QDialog
{
    Q_OBJECT

public:
    explicit userviewrentalhistory(QWidget *parent = nullptr, centerflow* center= nullptr);
    ~userviewrentalhistory();

private:
    Ui::userviewrentalhistory *ui;
    centerflow* center;
};

#endif // USERVIEWRENTALHISTORY_H
