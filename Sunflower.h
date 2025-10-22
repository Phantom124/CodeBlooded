#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant {
	private:
		std::string name;
		double price;

		PlantGrowthState* state;
		int waterLevel;
		int fertilizerLevel;

	public:
		Sunflower();
		Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Sunflower();
		double getPrice();
		std::string getName();
		void print();
		void add(Plant* extra);

		PlantGrowthState* getState();
		int getWaterLevel();
		int getFertilizerLevel();
		PlantGrowthState* setState(PlantGrowthState* state);
		int setWaterLevel(int waterLevel);
		int setFertilizerLevel(int fertilizerLevel);
};

#endif
