/**
 * @file Save10Discount.h
 * @brief Save10Discount.h — Header and declarations for the Save10Discount.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef SAVE_10_DISCOUNT_H
#define SAVE_10_DISCOUNT_H

#include "PriceStrategies.h"

class Save10Discount : public PriceStrategies
{
public:
    virtual ~Save10Discount() = default;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param amount The amount parameter used by the function.
 */

    virtual double applyPriceStrategy(double amount);
};

#endif
