#ifndef PLANT_H
#define PLANT_H

#include "PlantComponent.h"
#include "PlantGrowthState.h"
#include <string>

class Plant : public PlantComponent
{
protected:
	int careCount;
	int waterLevel;
	int fertilizerLevel;
	double waterRetention;
	double fertilizerRetention;

public:
	Plant();
	void hoursHasPassed();
	Plant(PlantGrowthState *state, int waterLevel, int fertilizerLevel);
	void waterPlant();
	void fertilizePlant();
	virtual void add(Plant *extra) = 0;
	virtual void print() = 0;
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
};

#endif
