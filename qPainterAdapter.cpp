#include "qPainterAdapter.h"

QPainterAdapter::QPainterAdapter(QPaintDevice* qPaintDevice) : qPainter(QPainter(qPaintDevice))
{

}

void QPainterAdapter::setBrush(int color)
{
    qPainter.setBrush(QBrush(color));
}

void QPainterAdapter::setPen(int color)
{
    qPainter.setPen(QColor(color));
}

void QPainterAdapter::drawEllipse(int x, int y, int length, int width)
{
    qPainter.drawEllipse(x, y, length, width);
}

void QPainterAdapter::drawRect(int x, int y, int length, int width)
{
    qPainter.drawRect(x, y, length, width);
}
