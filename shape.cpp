#include "shape.h"

void Shape::setPos(QPoint point)
{
    this->x = point.x();
    this->y = point.y();
    if(onPosChanged)
       onPosChanged(point);
}

void Shape::setColor(color::Color newBrushColor)
{
    this->brushColor = newBrushColor;
}

void Shape::setPosChangedListener(std::function<void(QPoint)> onPosChanged)
{
    this->onPosChanged = onPosChanged;
}
