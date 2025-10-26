#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantGrowthState.h"
#include <string>

class SeedlingState : public PlantGrowthState {
	public:
		PlantGrowthState* getNextState(int careCount);
		double getPriceEffect();
		std::string getStateName();
};

#endif
