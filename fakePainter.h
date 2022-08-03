#ifndef FAKEPAINTER_H
#define FAKEPAINTER_H

#include <QPainter>
#include "interfaceForPainting.h"

class FakePainter : public InterfaceForPainting
{
public:
    FakePainter() {};
    void setBrush(int color) override;
    void setPen(int color) override;
    void drawEllipse(int x, int y, int length, int width) override;
    void drawRect(int x, int y, int length, int width) override;
    int getSetBrushQuantity();
    int getSetPenQuantity();
    int getDrawEllipseQuantity();
    int getDrawRectQuantity();
private:
    QPainter qPainter;
    int setBrushQuantity = 0;
    int setPenQuantity = 0;
    int drawEllipseQuantity = 0;
    int drawRectQuantity = 0;
};

#endif // FAKEPAINTER_H
