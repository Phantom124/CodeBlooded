#ifndef NORMALPRICE_H
#define NORMALPRICE_H

#include "PriceStrategies.h"

class NormalPrice : public PriceStrategies
{
public:
	virtual ~NormalPrice() = default;
	virtual double applyPriceStrategy(double amount);
};

#endif
