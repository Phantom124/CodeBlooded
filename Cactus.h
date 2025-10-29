#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Cactus : public Plant {
	public:
		Cactus();
		// Cactus(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Cactus();

		std::string getName();

};

#endif