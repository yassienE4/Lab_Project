#ifndef MAINPAGEADMIN_H
#define MAINPAGEADMIN_H

#include <QDialog>

namespace Ui {
class mainpageadmin;
}

class mainpageadmin : public QDialog
{
    Q_OBJECT

public:
    explicit mainpageadmin(QWidget *parent = nullptr);
    ~mainpageadmin();

private:
    Ui::mainpageadmin *ui;
};

#endif // MAINPAGEADMIN_H
