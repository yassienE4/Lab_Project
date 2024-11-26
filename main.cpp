#include "mainwindow.h"
#include "centerflow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    qDebug()<<"running";

    return a.exec();
}
