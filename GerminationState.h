#ifndef GERMINATIONSTATE_H
#define GERMINATIONSTATE_H

#include "PlantGrowthState.h"
#include "SaplingState.h"

class GerminationState : public PlantGrowthState {
	public:
		PlantGrowthState* getNextState(int careCount);
		double getPriceEffect();
		std::string getStateName();
};

#endif
