#include "factorySingleton.h"

FactorySingleton* FactorySingleton::getInstance()
{
    static FactorySingleton factorySingletonItem;
    return &factorySingletonItem;
}

FactorySingleton::FactorySingleton()
{

}

const std::vector<std::unique_ptr<Factory>>* FactorySingleton::getVect()
{
    return &this->factoryVec;
}

std::vector<std::unique_ptr<Factory>>* FactoryAdder::getVect()
{
    return &FactorySingleton::getInstance()->factoryVec;
}
