#include "painterMock.h"

void PainterMock::setBrush(color::Color brushColor)
{
     qPainter.setBrush(QBrush(0x000080));
}

void PainterMock::setPen()
{
    qPainter.setPen(QColor(0xd4d4d4));
}

void PainterMock::drawEllipse(int x, int y, int length, int width)
{
    qPainter.drawEllipse(x, y, length, width);
    this->drawEllipseQuantity++;
}

void PainterMock::drawRect(int x, int y, int length, int width)
{
    qPainter.drawRect(x, y, length, width);
    this->drawRectQuantity++;
}

int PainterMock::getBrushColor()
{
    return this->brushColor;
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
