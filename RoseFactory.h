#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H

#include "PlantFactory.h"
#include "PlantGrowthState.h"
#include "Plant.h"
#include "Rose.h"

class RoseFactory : public PlantFactory {
	public:
		RoseFactory();
		~RoseFactory();
		Plant* createRose();
		Plant* createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel);

	private:
		PlantGrowthState* state;
		int waterLevel;
		int fertilizerLevel;

};

#endif
