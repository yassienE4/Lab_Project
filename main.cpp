#include "mainwindow.h"
#include "centerflow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    centerflow x;
    MainWindow w(nullptr, &x);
    w.show();


    return a.exec();
}
