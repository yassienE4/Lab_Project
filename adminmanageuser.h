#ifndef ADMINMANAGEUSER_H
#define ADMINMANAGEUSER_H

#include <QDialog>
#include "centerflow.h"  // Include this if centerflow is a class you are using

namespace Ui {
class adminmanageuser;
}

class adminmanageuser : public QDialog
{
    Q_OBJECT

public:
    explicit adminmanageuser(QWidget *parent = nullptr, centerflow *center = nullptr);
    ~adminmanageuser();

private slots:
    // Declare the slots for buttons and other UI elements
    void on_pushButton_add_clicked();
    void on_pushButton_edit_clicked();
    void on_pushButton_delete_clicked();

private:
    Ui::adminmanageuser *ui;
    centerflow *center;  // Pointer to centerflow (make sure this class exists)
};

#endif // ADMINMANAGEUSER_H
