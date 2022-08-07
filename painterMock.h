#ifndef PAINTERMOCK_H
#define PAINTERMOCK_H

#include <QPainter>
#include "interfaceForPainting.h"

class PainterMock : public InterfaceForPainting
{
public:
    PainterMock() {};
    void setBrush(color::Color) override;
    void setPen() override {};
    void drawEllipse(int x, int y, int length, int width) override;
    void drawRect(int x, int y, int length, int width) override;
    color::Color getBrushColor();
    color::Color getRectangleColor();
    color::Color getEllipseColor();
    int getDrawEllipseQuantity();
    int getDrawRectQuantity();

private:
    int drawEllipseQuantity = 0;
    int drawRectQuantity = 0;
    color::Color brushColor = color::Color::Empty;
    color::Color rectangleColor = color::Color::Empty;
    color::Color ellipseColor = color::Color::Empty;
};

#endif // PAINTERMOCK_H
