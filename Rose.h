/**
 * @file Rose.h
 * @brief Rose.h — Header and declarations for the Rose.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Rose : public Plant {
	public:
		Rose();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

		// Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Rose();

		// std::string getName();
};

#endif
