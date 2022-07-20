#include <QPainter>
#include "ellipse.h"
#include <QCursor>

void Ellipse::doPainting(QPainter &painter, std::vector<std::unique_ptr<Shape>> &objects, int movable_number, QPoint point, int number)
{
    painter.setPen(QColor(0xd4d4d4));
    painter.setBrush(QBrush(0xc56c00));
    if(movable_number > -1)
    {
        static_cast<Ellipse*> (objects[movable_number].get())->x = point.x();
        static_cast<Ellipse*> (objects[movable_number].get())->y = point.y();
    }
    painter.drawEllipse(static_cast<Ellipse*> (objects[number].get())->x, static_cast<Ellipse*> (objects[number].get())->y, static_cast<Ellipse*> (objects[number].get())->length, static_cast<Ellipse*> (objects[number].get())->width);
}

bool Ellipse::isInsideShape (QPoint point, int number)
{
    return this->x <= point.x() && this->x + this->length >= point.x() &&
    this->y <= point.y() && this->y + this->width >= point.y() && number == -1;
}
