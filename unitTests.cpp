#include "unitTests.h"
#include "painterMock.h"
#include "ellipse.h"
#include "rectangle.h"

bool checkIsInsideShapeEllipse()
{
    Ellipse ellipse;
    ellipse.setPos({0, 0});
    if(ellipse.isInsideShape({81, 48}) == false)
        return false;
    if(ellipse.isInsideShape({82, 48}) == true)
        return false;
    if(ellipse.isInsideShape({80, 48}) == false)
        return false;
    return true;
}

bool checkIsInsideShapeRect()
{
    Rectangle rectangle;
    rectangle.setPos({0, 0});
    if(rectangle.isInsideShape({0, 0}) == false)
        return false;
    if(rectangle.isInsideShape({0, -1}) == true)
        return false;
    if(rectangle.isInsideShape({0, 1})== false)
        return false;
    return true;
}

bool checkDoPainting()
{
    Ellipse ellipse;
    Rectangle rect;
    PainterMock painterMock;
    ellipse.doPainting(painterMock);
    if(painterMock.getDrawEllipseQuantity() != 0)
        return false;
    ellipse.setColor(color::Color::Blue);
    ellipse.doPainting(painterMock);
    if(painterMock.getDrawEllipseQuantity() != 1)
        return false;
    rect.doPainting(painterMock);
    if(painterMock.getDrawRectQuantity() != 0)
        return false;
    rect.setColor(color::Color::Blue);
    rect.doPainting(painterMock);
    if(painterMock.getDrawRectQuantity() != 1)
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
