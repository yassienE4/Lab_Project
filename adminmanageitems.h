#ifndef ADMINMANAGEITEMS_H
#define ADMINMANAGEITEMS_H

#include <QDialog>

namespace Ui {
class adminmanageitems;
}

class adminmanageitems : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanageitems(QWidget *parent = nullptr);
    ~adminmanageitems();

private:
    Ui::adminmanageitems *ui;
};

#endif // ADMINMANAGEITEMS_H
