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

private slots:
    void on_pushButton_Browse_clicked();

    void on_pushButton_Reserve_clicked();

    void on_pushButton_View_clicked();

    void on_pushButton_History_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::mainpageuser *ui;
};

#endif // MAINPAGEUSER_H