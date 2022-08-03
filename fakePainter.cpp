#include "fakePainter.h"

void FakePainter::setBrush(int color)
{
    qPainter.setBrush(QBrush(color));
    this->setBrushQuantity++;
}

void FakePainter::setPen(int color)
{
    qPainter.setPen(QColor(color));
    this->setPenQuantity++;
}

void FakePainter::drawEllipse(int x, int y, int length, int width)
{
    qPainter.drawEllipse(x, y, length, width);
    this->drawEllipseQuantity++;
}

void FakePainter::drawRect(int x, int y, int length, int width)
{
    qPainter.drawRect(x, y, length, width);
    this->drawRectQuantity++;
}

int FakePainter::getSetBrushQuantity()
{
    return this->setBrushQuantity;
}

int FakePainter::getSetPenQuantity()
{
    return this->setPenQuantity;
}

int FakePainter::getDrawEllipseQuantity()
{
    return this->drawEllipseQuantity;
}

int FakePainter::getDrawRectQuantity()
{
    return this->drawRectQuantity;
}


