/**
 * @file Cactus.h
 * @brief Cactus.h — Header and declarations for the Cactus.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Cactus : public Plant {
	public:
		Cactus();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */
		// Cactus(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
		~Cactus();

		// std::string getName();

};

#endif
