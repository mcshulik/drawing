#include <QPainter>
#include "rectangle.h"
#include <QCursor>

void Rectangle::doPainting(QPainter &painter, QPoint point)
{    
    painter.setPen(QColor(0xd4d4d4));
    painter.setBrush(QBrush(0xc56c00));
    painter.drawRect(this->x, this->y, this->length, this->width);
}

bool Rectangle::isInsideShape (QPoint point)
{
    return this->x <= point.x() && this->x + this->length >= point.x() && this->y <= point.y() && this->y + this->width >= point.y();
}
