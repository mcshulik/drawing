#include "painterMock.h"

void PainterMock::setBrush(color::Color brushColor)
{
     this->currentColor = brushColor;
}

void PainterMock::drawEllipse(int x, int y, int length, int width)
{
    this->ellipseColor = this->currentColor;
    this->drawEllipseQuantity++;
}

void PainterMock::drawRect(int x, int y, int length, int width)
{
    this->drawRectQuantity++;
    this->rectangleColor = this->currentColor;
}

int PainterMock::getBrushColor()
{
    return this->currentColor;
}

int PainterMock::getDrawEllipseQuantity()
{
    return this->drawEllipseQuantity;
}

int PainterMock::getDrawRectQuantity()
{
    return this->drawRectQuantity;
}

int PainterMock::getRectangleColor()
{
    return this->rectangleColor;
}

int PainterMock::getEllipseColor()
{
    return this->ellipseColor;
}
