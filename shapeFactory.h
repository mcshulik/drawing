#ifndef SIMPLESHAPEFACTORY_H
#define SIMPLESHAPEFACTORY_H

#endif // SIMPLESHAPEFACTORY_H

#include "factory.h"
#include "rectangle.h"
#include "ellipse.h"

class ShapeFactory : public Factory
{
  public:
    Shape* createCurvedInstance() override
    {
      return new Ellipse;
    }
    Shape* createStraightInstance() override
    {
      return new Rectangle;
    }
};
