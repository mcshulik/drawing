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
    virtual void doPainting(QPainter &painter, QPoint point) = 0;
    void setPos(QPoint point);
    virtual bool isInsideShape (QPoint point) = 0;
  protected:
    int x, y;
};
