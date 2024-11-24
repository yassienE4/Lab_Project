#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <centerflow.h>
#include <QDialog>

namespace Ui {
class loginwindow;
}

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr, centerflow *center = nullptr);
    ~loginwindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::loginwindow *ui;
    centerflow *center;
};

#endif // LOGINWINDOW_H
