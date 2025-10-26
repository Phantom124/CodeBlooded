#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Cactus : public Plant {
	private:
		std::string name;
		double price;

		PlantGrowthState* state;


	public:
		Cactus();
		Cactus(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Cactus();

		std::string getName();
		PlantGrowthState* getState();
		int getWaterLevel();
		int getFertilizerLevel();

};

#endif
