#ifndef FACTORY_H
#define FACTORY_H

#endif // FACTORY_H

#include "shape.h"

class Factory
{
  public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};
