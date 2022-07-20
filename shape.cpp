#include "shape.h"

void Shape::setPos(QPoint point)
{
    this->x = point.x();
    this->y = point.y();
}
