#ifndef NORMALPRICE_H
#define NORMALPRICE_H

#include "PriceStrategies.h"

class NormalPrice : public PriceStrategies
{
public:
	virtual double priceStrategy() { return 1; };
};

#endif
