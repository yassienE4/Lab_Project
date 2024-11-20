#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class registerwindow;
}

class registerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

private slots:
    void on_pushButton_Register_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::registerwindow *ui;
};

#endif // REGISTERWINDOW_H
