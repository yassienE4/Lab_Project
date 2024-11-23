#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QDialog>

namespace Ui {
class adminmainpage;
}

class adminmainpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminmainpage(QWidget *parent = nullptr);
    ~adminmainpage();

private:
    Ui::adminmainpage *ui;
};

#endif // ADMINMAINPAGE_H
