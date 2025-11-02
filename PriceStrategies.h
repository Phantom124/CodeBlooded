#ifndef PRICESTRATEGIES_H
#define PRICESTRATEGIES_H
#include "PlantComponent.h"
#include <vector>
class PriceStrategies
{
public:
    virtual ~PriceStrategies() = default;
    virtual double applyPriceStrategy(double amount) = 0;
};
#endif
