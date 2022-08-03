#include <QPainter>
#include "rectangle.h"
#include <QCursor>

Rectangle::Rectangle()
{
    this->length = rectLength;
    this->width = rectWidth;
    this->x = 0;
    this->y = 0;
}

void Rectangle::doPainting(InterfaceForPainting &interfaceForPainting)
{    
    interfaceForPainting.setPen(0xd4d4d4);
    interfaceForPainting.setBrush(0xc56c00);
    interfaceForPainting.drawRect(this->x, this->y, this->length, this->width);
}

bool Rectangle::isInsideShape (QPoint point)
{
    return this->x <= point.x() && this->x + this->length >= point.x() && this->y <= point.y() && this->y + this->width >= point.y();
}
