#ifndef FACTORY_H
#define FACTORY_H

#include "shape.h"

class Factory
{
  public:
    virtual ~Factory() {}
    virtual Shape* createShape() = 0;
    virtual const char* getName() = 0;
};

#endif // FACTORY_H
