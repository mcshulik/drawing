#ifndef PAINTERMOCK_H
#define PAINTERMOCK_H

#include <QPainter>
#include "interfaceForPainting.h"

class PainterMock : public InterfaceForPainting
{
public:
    PainterMock() {};
    void setBrush(color::Color) override;
    void setPen() override;
    void drawEllipse(int x, int y, int length, int width) override;
    void drawRect(int x, int y, int length, int width) override;
    int getBrushColor();
    int getPenColor();
    int getRectangleColor();
    int getEllipseColor();
    int getDrawEllipseQuantity();
    int getDrawRectQuantity();
private:
    QPainter qPainter;
    int penColor = color::Empty;
    int drawEllipseQuantity = 0;
    int drawRectQuantity = 0;
    color::Color currentColor = color::Color::Empty;
    color::Color brushColor;
    color::Color rectangleColor = color::Color::Empty;
    color::Color ellipseColor = color::Color::Empty;
};

#endif // PAINTERMOCK_H
