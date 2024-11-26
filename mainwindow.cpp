#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    loginwindow *l = new loginwindow();
    this->hide();
    l->show();
}


void MainWindow::on_pushButton_Regiter_clicked()
{
    registerwindow *r = new registerwindow();
    this->hide();
    r->show();
}

