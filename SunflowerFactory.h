#ifndef SUNFLOWERFACTORY_H
#define SUNFLOWERFACTORY_H

#include "PlantFactory.h"
#include "PlantGrowthState.h"
#include "Plant.h"

class SunflowerFactory : public PlantFactory {
	public:
		SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* greenHouse);
		~SunflowerFactory();
		Plant* createPlant();
		// Plant* createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
};

#endif