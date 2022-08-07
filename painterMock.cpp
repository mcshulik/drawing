#include "painterMock.h"

void PainterMock::setBrush(color::Color brushColor)
{
    this->brushColor = brushColor;
}

void PainterMock::drawEllipse(int x, int y, int length, int width)
{
    this->ellipseColor = this->brushColor;
    this->drawEllipseQuantity++;
}

void PainterMock::drawRect(int x, int y, int length, int width)
{
    this->drawRectQuantity++;
    this->rectangleColor = this->brushColor;
}

color::Color PainterMock::getBrushColor()
{
    return this->brushColor;
}

int PainterMock::getDrawEllipseQuantity()
{
    return this->drawEllipseQuantity;
}

int PainterMock::getDrawRectQuantity()
{
    return this->drawRectQuantity;
}

color::Color PainterMock::getRectangleColor()
{
    return this->rectangleColor;
}

color::Color PainterMock::getEllipseColor()
{
    return this->ellipseColor;
}
