#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantGrowthState.h"

class DeadState : public PlantGrowthState {
	public:
		PlantGrowthState* getNextState(int careCount, int health);
		double getPriceEffect();
		std::string getStateName();
};

#endif
