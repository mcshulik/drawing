#ifndef ELLIPSEFACTORY_H
#define ELLIPSEFACTORY_H

#include "ellipse.h"
#include "factory.h"
#include <QPushButton>

class EllipseFactory : public Factory
{
  public:
    Shape* createShape() override;
    virtual const char* getName() override;
};

#endif // ELLIPSEFACTORY_H
