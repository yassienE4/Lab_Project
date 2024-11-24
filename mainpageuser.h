#ifndef MAINPAGEUSER_H
#define MAINPAGEUSER_H

#include <QDialog>

namespace Ui {
class mainpageuser;
}

class mainpageuser : public QDialog
{
    Q_OBJECT

public:
    explicit mainpageuser(QWidget *parent = nullptr);
    ~mainpageuser();

private:
    Ui::mainpageuser *ui;
};

#endif // MAINPAGEUSER_H
