#include <QPainter>
#include "ellipse.h"
#include <QCursor>

Ellipse::Ellipse()
{
    this->length = ellipseLength;
    this->width = ellipseWidth;
    this->x = 0;
    this->y = 0;
}

void Ellipse::doPainting(InterfaceForPainting &interfaceForPainting)
{
    if(this->brushColor == color::Color::Empty)
        return;
    interfaceForPainting.setPen();
    interfaceForPainting.setBrush(this->brushColor);
    interfaceForPainting.drawEllipse(this->x, this->y, this->length, this->width);
}

bool Ellipse::isInsideShape (QPoint point)
{
    if ((float)(point.x() - this->x - (float)(this->length / 2)) * (float)(point.x() - this->x - (float)(this->length / 2)) / ((float)(this->length / 2) * (float)(this->length / 2)) +
        (float)(point.y() - this->y - (float)(this->width / 2)) * (float)(point.y() - this->y - (float)(this->width / 2)) / ((float)(this->width / 2) *  (float)(this->width / 2)) <= 1)
            return true;
        else return false;
}
