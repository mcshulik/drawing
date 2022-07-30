#include "ellipseFactory.h"
#include "factorySingleton.h"

namespace
{
    class Adder : public FactoryAdder
    {
    public:
        Adder()
        {
            std::unique_ptr<Factory> fact = std::make_unique<EllipseFactory>();
            getVect()->push_back(std::move(fact));
        }
    }adder;
}

const char* EllipseFactory::getName()
{
    return "Ellipse";
}
