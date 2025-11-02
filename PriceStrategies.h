#ifndef PRICESTRATEGIES_H
#define PRICESTRATEGIES_H
#include "PlantComponent.h"
#include <vector>
#include <iostream>
class PriceStrategies
{
public:
    virtual ~PriceStrategies() = default;
    virtual double applyPriceStrategy(double amount) = 0;
};
#endif
