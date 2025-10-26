#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant {
	private:
		std::string name;
		double price;
		PlantGrowthState* state;


	public:
		Sunflower();
		Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Sunflower();

		std::string getName();
		PlantGrowthState* getState();
		int getWaterLevel();
		int getFertilizerLevel();
};

#endif
