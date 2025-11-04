/**
 * @file Sunflower.h
 * @brief Sunflower.h — Header and declarations for the Sunflower.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant
{
public:
	Sunflower();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

	// Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
	~Sunflower();

	// std::string getName();
};

#endif

