#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include "PlantComponent.h"
#include <string>

class PlantDecorator : public PlantComponent
{
protected:
	PlantComponent *nextDecorator;
	// PlantComponent *plantComponent;

public:
	PlantDecorator();
	~PlantDecorator();
	virtual void add(PlantComponent *extra);
	// virtual void printPlant();    // Removed due to no one calling the function
	virtual double getPrice();
	virtual std::string getName();
};

#endif