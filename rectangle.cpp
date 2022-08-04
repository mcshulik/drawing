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
    if(this->brushColor == color::Color::Empty)
        return;
    interfaceForPainting.setPen();
    interfaceForPainting.setBrush(this->brushColor);
    interfaceForPainting.drawRect(this->x, this->y, this->length, this->width);
}

bool Rectangle::isInsideShape (QPoint point)
{
    return this->x <= point.x() && this->x + this->length >= point.x() && this->y <= point.y() && this->y + this->width >= point.y();
}
