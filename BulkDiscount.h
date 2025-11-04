/**
 * @file BulkDiscount.h
 * @brief Pricing strategy that applies a bulk discount to orders meeting quantity/amount thresholds.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef BULK_DISCOUNT_H
#define BULK_DISCOUNT_H

#include "PriceStrategies.h"

class BulkDiscount : public PriceStrategies
{
public:
    virtual ~BulkDiscount() = default;
/**
 * @brief Calculate the adjusted price using a bulk-discount rule.
 * @param amount The original total amount (before discount).
 * @return double The adjusted total amount after applying any bulk discount.
 */

     virtual double applyPriceStrategy(double amount);
};

#endif
