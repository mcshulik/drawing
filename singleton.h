#ifndef SINGLETON_H
#define SINGLETON_H

#include "factory.h"

class FactorySingleton
{
  public:
    static FactorySingleton* getInstance();
  private:
    FactorySingleton() {}
    FactorySingleton(const FactorySingleton&) = delete;
    std::vector<Factory> factoryVec;
};

#endif // SINGLETON_H
