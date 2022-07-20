#ifndef ELLIPSE_H
#define ELLIPSE_H

#endif // ELLIPSE_H

#define ellipseLength 90
#define ellipseWidth 60

#pragma once

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
    void doPainting(QPainter &painter, std::vector<std::unique_ptr<Shape>> &objects, int movable_number, QPoint point, int number) override;
    bool isInsideShape (QPoint point, int number) override;
  private:
    int length = ellipseLength, width = ellipseWidth;
};
