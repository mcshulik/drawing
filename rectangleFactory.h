#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "rectangle.h"
#include "factory.h"

class RectangleFactory : public Factory
{
  public:
    Shape* createShape() override
    {
      return new Rectangle;
    }
    virtual const char* getName() override;
};

#endif // RECTANGLEFACTORY_H
