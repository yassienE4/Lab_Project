#ifndef USERBROWSEITEMS_H
#define USERBROWSEITEMS_H

#include <QDialog>

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
};

#endif // USERBROWSEITEMS_H
