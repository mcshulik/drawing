#ifndef FACTORYSINGLETON_H
#define FACTORYSINGLETON_H

#include "factory.h"
#include "ellipseFactory.h"
#include "rectangleFactory.h"

class FactoryAdder
{
  protected:
    std::vector<std::unique_ptr<Factory>>* getVect();
};

class FactorySingleton
{
  public:
    static FactorySingleton* getInstance();
    const std::vector<std::unique_ptr<Factory>>* getVect();
  private:
    FactorySingleton() = default;
    FactorySingleton(const FactorySingleton&) = delete;
    std::vector<std::unique_ptr<Factory>> factoryVec;
    friend class FactoryAdder;
};

#endif // FACTORYSINGLETON_H
