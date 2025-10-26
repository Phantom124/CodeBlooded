#ifndef WATER_H
#define WATER_H
#include <string>
#include "PlantGrowthState.h"

class Water {
	public:
		Water();
		virtual ~Water() = default;
		virtual int effect() = 0;
		virtual Water* getNextState(int currentLevel, int lowFertilizerLevel) = 0;
		virtual std::string getStateName() = 0;
};

#endif
