#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include "interfaceForPainting.h"

class Shape
{
  public:
    Shape() {}
    virtual ~Shape() {}
    virtual void doPainting(InterfaceForPainting &interfaceForPainting) = 0;
    void setPos(QPoint point);
    virtual bool isInsideShape (QPoint point) = 0;
    void setPosChangedListener(std::function<void(QPoint)> onPosChanged);
    void setColor(color::Color newBrushColor);
  protected:
    int x, y;
    color::Color brushColor = color::Color::Empty;
  private:
    std::function<void(QPoint)> onPosChanged;
};

#endif // SHAPE_H
