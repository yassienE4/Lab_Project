#include "mainwindow.h"
#include "centerflow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    centerflow x;
    MainWindow w(nullptr, &x);
    w.show();

    //
    // 1. NO STRINGS ONLY QSTRING
    //
    // 2.filename objname(nullptr, &center);
    // 2.mainwindow w(nullptr)
    // 2.w->show()
    //
    // 3. center.getvectoruser();

 /*   if(clicked button left)
        i--
    if(clicked right)
        i++

        array[i];
    for()



    return a.exec();
*/
}
