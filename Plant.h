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
		void add(Plant *extra);
		void print();
		double getPrice();
		std::string getName();
};

#endif
