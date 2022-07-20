#ifndef RECTANGLE_H
#define RECTANGLE_H

#endif // RECTANGLE_H

#define rectLength 90
#define rectWidth 60

#pragma once

#include "shape.h"

class Rectangle : public Shape
{

  public:
    Rectangle()
    {
        this->length = rectLength;
        this->width = rectWidth;
        this->x = 0;
        this->y = 0;
    }
    ~Rectangle() {};
    void doPainting(QPainter &painter, std::vector<std::unique_ptr<Shape>> &objects, int movable_number, QPoint point, int number) override;
    bool isInsideShape (QPoint point, int number) override;
  private:
    int length = rectLength, width = rectWidth;
};
