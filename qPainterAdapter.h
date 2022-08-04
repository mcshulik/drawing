#ifndef QPAINTERADAPTER_H
#define QPAINTERADAPTER_H
#include "interfaceForPainting.h"
#include <QPainter>

class QPainterAdapter : public InterfaceForPainting
{
public:
    QPainterAdapter(QPaintDevice *qPaintDevice);
    void setBrush(color::Color) override;
    void setPen() override;
    void drawEllipse(int x, int y, int length, int width) override;
    void drawRect(int x, int y, int length, int width) override;
private:
    QPainter qPainter;
};

#endif // QPAINTERADAPTER_H
