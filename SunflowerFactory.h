#ifndef SUNFLOWERFACTORY_H
#define SUNFLOWERFACTORY_H

#include "PlantFactory.h"
#include "PlantGrowthState.h"
#include "Plant.h"

class SunflowerFactory : public PlantFactory {
	public:
		SunflowerFactory();
		~SunflowerFactory();
		Plant* createSunflower();
		Plant* createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);

	private:
		PlantGrowthState* state;
		int waterLevel;
		int fertilizerLevel;
};

#endif
