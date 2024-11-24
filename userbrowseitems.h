#ifndef USERBROWSEITEMS_H
#define USERBROWSEITEMS_H

#include <QDialog>
#include <QVector>
#include "item.h"
#include "centerflow.h"

namespace Ui {
class userbrowseitems;
}

class userbrowseitems : public QDialog
{
    Q_OBJECT

public:
    explicit userbrowseitems(QWidget *parent = nullptr);
    ~userbrowseitems();

private:
    Ui::userbrowseitems *ui;
    QVector<item> *items;
    void searchItems();
};

#endif // USERBROWSEITEMS_H
