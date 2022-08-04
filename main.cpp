#include "mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include <QApplication>
#include "unitTests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!testAllFuncs())
        return 0;
    MainWindow w;
    w.show();
    return a.exec();
}
