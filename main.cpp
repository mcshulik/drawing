#include "mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include <QApplication>
#include "fakePainter.h"


bool checkIsInsideShapeEllipse()
{
    Ellipse ellipse;
    QPoint qpoint;
    qpoint.setX(0);
    qpoint.setY(0);
    ellipse.setPos(qpoint);
    qpoint.setX(81);
    qpoint.setY(48);
    if(!ellipse.isInsideShape(qpoint))
        return false;
    qpoint.setX(82);
    qpoint.setY(48);
    if(ellipse.isInsideShape(qpoint))
        return false;
    qpoint.setX(80);
    qpoint.setY(48);
    if(!ellipse.isInsideShape(qpoint))
        return false;
    return true;
}

bool checkIsInsideShapeRect()
{
    Rectangle rectangle;
    QPoint qpoint;
    qpoint.setX(0);
    qpoint.setY(0);
    rectangle.setPos(qpoint);
    if(!rectangle.isInsideShape(qpoint))
        return false;
    qpoint.setY(-1);
    if(rectangle.isInsideShape(qpoint))
        return false;
    qpoint.setY(1);
    if(!rectangle.isInsideShape(qpoint))
        return false;
    return true;
}

bool checkDoPainting()
{
    Ellipse ellipse;
    Rectangle rect;
    FakePainter fakePainter;
    ellipse.doPainting(fakePainter);
    if(fakePainter.getDrawEllipseQuantity() != 1 || fakePainter.getSetBrushQuantity() != 1 || fakePainter.getSetPenQuantity() != 1)
        return false;
    rect.doPainting(fakePainter);
    if(fakePainter.getDrawRectQuantity() != 1 || fakePainter.getSetBrushQuantity() != 2 || fakePainter.getSetPenQuantity() != 2)
        return false;
    return true;
}

bool testAllFuncs()
{
    if(!checkIsInsideShapeEllipse())
        return false;
    if(!checkIsInsideShapeRect())
        return false;
    if(!checkDoPainting())
        return false;
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!testAllFuncs())
        return 0;
    MainWindow w;
    w.show();
    return a.exec();
}
