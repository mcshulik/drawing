#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

class Shape
{

  public:
    Shape() {}
    virtual ~Shape() {}
    virtual void doPainting(QPainter &painter) = 0;
    void setPos(QPoint point);
    virtual bool isInsideShape (QPoint point) = 0;
  protected:
    int x, y;
};

#endif // SHAPE_H
