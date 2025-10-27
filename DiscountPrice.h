#ifndef DISCOUNTPRICE_H
#define DISCOUNTPRICE_H

#include "PriceStrategies.h"

class DiscountPrice : public PriceStrategies
{
public:
	virtual double priceStrategy() { return 0.8; };
};

#endif
