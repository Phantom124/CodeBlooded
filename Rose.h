#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Rose : public Plant {
	private:
		std::string name;
		double price;

		PlantGrowthState* state;


	public:
		Rose();
		Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Rose();
		double getPrice();
		std::string getName();
		// void add(Plant* extra);

		PlantGrowthState* getState();
		int getWaterLevel();
		int getFertilizerLevel();

};

#endif
