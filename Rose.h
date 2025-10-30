#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Rose : public Plant {
	public:
		Rose();
		// Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Rose();

		// std::string getName();
};

#endif