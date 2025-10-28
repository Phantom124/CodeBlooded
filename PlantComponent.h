#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>

class PlantComponent
{
private:
	double price;
	std::string name;

public:
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	virtual void addPlantComponent(PlantComponent *plantComponent) = 0;
};

#endif
