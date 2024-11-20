#ifndef ADMINMANAGEUSERS_H
#define ADMINMANAGEUSERS_H

#include <QDialog>

namespace Ui {
class adminmanageusers;
}

class adminmanageusers : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanageusers(QWidget *parent = nullptr);
    ~adminmanageusers();

private slots:
    void on_pushButton_ManageUsers_clicked();

private:
    Ui::adminmanageusers *ui;
};

#endif // ADMINMANAGEUSERS_H
