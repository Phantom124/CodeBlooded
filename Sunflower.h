#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant
{
public:
	Sunflower();
	// Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
	~Sunflower();

	// std::string getName();
};

#endif

