#ifndef PLANT_H
#define PLANT_H

#include "PlantComponent.h"
#include "PlantGrowthState.h"
#include <string>

using namespace std;

class Plant : public PlantComponent
{
	protected:
		string id;
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
		string getName();
		string getId();
		string getMaturityState();
};

#endif
