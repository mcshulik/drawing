#include "rectangleFactory.h"
#include "factorySingleton.h"

namespace
{
    class Adder : public FactoryAdder
    {
    public:
        Adder()
        {
            std::unique_ptr<Factory> fact = std::make_unique<RectangleFactory>();
            getVect()->push_back(std::move(fact));
        }
    }adder;
}

Shape* RectangleFactory::createShape()
{
  return new Rectangle;
}

const char* RectangleFactory::getName()
{
    return "Rectangle";
}
