#ifndef RESERVEITEMS_H
#define RESERVEITEMS_H

#include <QDialog>

namespace Ui {
class reserveitems;
}

class reserveitems : public QDialog
{
    Q_OBJECT

public:
    explicit reserveitems(QWidget *parent = nullptr);
    ~reserveitems();

private:
    Ui::reserveitems *ui;
};

#endif // RESERVEITEMS_H
