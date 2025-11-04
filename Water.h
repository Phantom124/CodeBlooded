/**
 * @file Water.h
 * @brief Water.h — Header and declarations for the Water.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
