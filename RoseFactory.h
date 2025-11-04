/**
 * @file RoseFactory.h
 * @brief RoseFactory.h — Header and declarations for the RoseFactory.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H

#include "PlantFactory.h"
#include "PlantGrowthState.h"
#include "Plant.h"
#include "Rose.h"

class RoseFactory : public PlantFactory {
	public:
/**
 * @brief Execute the function's primary operation.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 */

		RoseFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon);
		~RoseFactory();
		Plant* createPlant();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

		// Plant* createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel);

	private:
		// PlantGrowthState* state;
		int waterLevel;
		int fertilizerLevel;

};

#endif
