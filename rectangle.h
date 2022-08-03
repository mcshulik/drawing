#ifndef RECTANGLE_H
#define RECTANGLE_H

#define rectLength 90
#define rectWidth 60

#include "shape.h"

class Rectangle : public Shape
{

  public:
    Rectangle();
    ~Rectangle() {};
    void doPainting(InterfaceForPainting &interfaceForPainting) override;
    bool isInsideShape (QPoint point) override;
  private:
    int length = rectLength, width = rectWidth;
};

#endif // RECTANGLE_H
