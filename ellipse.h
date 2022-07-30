#ifndef ELLIPSE_H
#define ELLIPSE_H

#define ellipseLength 90
#define ellipseWidth 60

#include "shape.h"

class Ellipse : public Shape
{

  public:
    Ellipse()
    {
        this->length = ellipseLength;
        this->width = ellipseWidth;
        this->x = 0;
        this->y = 0;
    }
    ~Ellipse() {};
    void doPainting(QPainter &painter) override;
    bool isInsideShape (QPoint point) override;
  private:
    int length = ellipseLength, width = ellipseWidth;
};

#endif // ELLIPSE_H
