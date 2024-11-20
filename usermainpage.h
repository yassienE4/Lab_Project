#ifndef USERMAINPAGE_H
#define USERMAINPAGE_H

#include <QDialog>

namespace Ui {
class userlogin;
}

class userlogin : public QDialog
{
    Q_OBJECT

public:
    explicit userlogin(QWidget *parent = nullptr);
    ~userlogin();

private:
    Ui::userlogin *ui;
};

#endif // USERMAINPAGE_H
