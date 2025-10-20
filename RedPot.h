#ifndef REDPOT_H
#define REDPOT_H

#include "PlantDecorator.h"
#include <string>

class RedPot : public PlantDecorator {


public:
	RedPot();
	~RedPot();
	double getPrice();
	std::string getName();
	void print();
};

#endif
