#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include "PlantComponent.h"
#include <string>

class PlantDecorator : public PlantComponent
{
protected:
	PlantComponent *myPlant;

public:
	PlantDecorator();
	~PlantDecorator();
	virtual void addPlant(PlantComponent *extra);
	virtual void printPlant();
	virtual double getPrice();
	virtual std::string getName();
};

#endif