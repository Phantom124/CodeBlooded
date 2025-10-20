#ifndef PLANTSNAPSHOT_H
#define PLANTSNAPSHOT_H

#include "Plant.h"
#include <string>

class PlantSnapshot {
	private:
		std::string plantType;
		std::string growthState;
		int waterLevel;
		int fertilizerLevel;

	public:
		PlantSnapshot(Plant* plant);
		std::string getGrowthState();
		int getWaterLevel();
		int getFertilizerLevel();
};

#endif
