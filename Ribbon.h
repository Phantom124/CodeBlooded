#ifndef RIBBON_H
#define RIBBON_H

#include "PlantDecorator.h"
#include <string>

class Ribbon : public PlantDecorator
{

public:
	Ribbon();
	~Ribbon() = default;
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
};

#endif
