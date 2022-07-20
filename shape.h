#ifndef SHAPE_H
#define SHAPE_H

#endif // SHAPE_H

#pragma once

#include <QPainter>

class Shape
{

  public:
    Shape() {};
    virtual ~Shape() {};
    virtual void doPainting(QPainter &painter, std::vector<std::unique_ptr<Shape>> &objects, int movable_number, QPoint point, int number) = 0;
    void setPos(QPoint point);
    virtual bool isInsideShape (QPoint point, int number) = 0;
  protected:
    int x, y;
};
