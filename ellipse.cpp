#include <QPainter>
#include "ellipse.h"
#include <QCursor>

void Ellipse::doPainting(QPainter &painter, QPoint point)
{
    painter.setPen(QColor(0xd4d4d4));
    painter.setBrush(QBrush(0xc56c00));
    painter.drawEllipse(this->x, this->y, this->length, this->width);
}

bool Ellipse::isInsideShape (QPoint point)
{
    if((float)((float)((point.x() - this->x - this->length / 2) * (point.x() - this->x - this->length / 2)) / (float)((this->length * this->length / 4))) +
       (float)((float)((this->y + this->width / 2 - point.y()) * (this->y + this->width / 2 - point.y())) / (float)((this->width * this->length / 4))) <= 1)
        return true;
    else
        return false;
}
