#ifndef SAPLINGSTATE_H
#define SAPLINGSTATE_H

#include "PlantGrowthState.h"
#include <string>

class SaplingState : public PlantGrowthState {
	public:
		PlantGrowthState* getNextState(int careCount, int health);
		double getPriceEffect();
		std::string getStateName();
};

#endif
