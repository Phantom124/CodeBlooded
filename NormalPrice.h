/**
 * @file NormalPrice.h
 * @brief NormalPrice.h — Header and declarations for the NormalPrice.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef NORMALPRICE_H
#define NORMALPRICE_H

#include "PriceStrategies.h"

class NormalPrice : public PriceStrategies
{
public:
	virtual ~NormalPrice() = default;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param amount The amount parameter used by the function.
 */

	virtual double applyPriceStrategy(double amount);
};

#endif
