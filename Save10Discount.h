#ifndef SAVE_10_DISCOUNT_H
#define SAVE_10_DISCOUNT_H

#include "PriceStrategies.h"

class Save10Discount : public PriceStrategies
{
public:
    virtual ~Save10Discount() = default;
    virtual double applyPriceStrategy(double amount);
};

#endif
