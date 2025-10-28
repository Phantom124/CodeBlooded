#ifndef REDPOT_H
#define REDPOT_H

#include "PlantDecorator.h"
#include <string>

class RedPot : public PlantDecorator
{

public:
	RedPot();
	~RedPot() = default;
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
};

#endif
