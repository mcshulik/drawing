#include "painterMock.h"

void PainterMock::setBrush(color::Color brushColor)
{
     qPainter.setBrush(QBrush(0x000080));
     this->currentColor = brushColor;
}

void PainterMock::setPen()
{
    qPainter.setPen(QColor(0xd4d4d4));
}

void PainterMock::drawEllipse(int x, int y, int length, int width)
{
    qPainter.drawEllipse(x, y, length, width);
    this->ellipseColor = this->currentColor;
    this->drawEllipseQuantity++;
}

void PainterMock::drawRect(int x, int y, int length, int width)
{
    qPainter.drawRect(x, y, length, width);
    this->drawRectQuantity++;
    this->rectangleColor = this->currentColor;
}

int PainterMock::getBrushColor()
{
    return this->currentColor;
}

int PainterMock::getPenColor()
{
    return this->penColor;
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
