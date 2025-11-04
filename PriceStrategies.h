/**
 * @file PriceStrategies.h
 * @brief PriceStrategies.h — Header and declarations for the PriceStrategies.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
