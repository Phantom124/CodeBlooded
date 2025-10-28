#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>

class PlantDecorator : public Plant
{
public:
	PlantDecorator();
	~PlantDecorator();
	void add(Plant *extra);
	virtual void print();
	virtual double getPrice();
	virtual std::string getName();

protected:
	Plant *myPlant;
};

#endif
