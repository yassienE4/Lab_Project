#ifndef USERMAINPAGE_H
#define USERMAINPAGE_H

#include <QDialog>

namespace Ui {
class usermainpage;
}

class usermainpage : public QDialog
{
    Q_OBJECT

public:
    explicit usermainpage(QWidget *parent = nullptr);
    ~usermainpage();

private:
    Ui::usermainpage *ui;
};

#endif // USERMAINPAGE_H
