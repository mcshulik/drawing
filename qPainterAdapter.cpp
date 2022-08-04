#include "qPainterAdapter.h"

QPainterAdapter::QPainterAdapter(QPaintDevice* qPaintDevice) : qPainter(QPainter(qPaintDevice))
{

}

void QPainterAdapter::setBrush(color::Color brushColor)
{
    switch (brushColor)
    {
        case color::Blue:
            qPainter.setBrush(QBrush(0x000080));
            break;
        case color::Brown:
            qPainter.setBrush(QBrush(0xc56c00));
            break;
        case color::Green:
            qPainter.setBrush(QBrush(0x00a86b));
            break;
        case color::Red:
            qPainter.setBrush(QBrush(0x560319));
            break;
        case color::Grey:
            qPainter.setBrush(QBrush(0xd4d4d4));
            break;
        default:
            break;
    }
}

void QPainterAdapter::setPen()
{
    qPainter.setPen(QColor(0xd4d4d4));
}

void QPainterAdapter::drawEllipse(int x, int y, int length, int width)
{
    qPainter.drawEllipse(x, y, length, width);
}

void QPainterAdapter::drawRect(int x, int y, int length, int width)
{
    qPainter.drawRect(x, y, length, width);
}
