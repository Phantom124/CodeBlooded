#ifndef BULK_DISCOUNT_H
#define BULK_DISCOUNT_H

#include "PriceStrategies.h"

class BulkDiscount : public PriceStrategies
{
public:
    virtual ~BulkDiscount() = default;
    virtual double applyPriceStrategy(double amount);
};

#endif
