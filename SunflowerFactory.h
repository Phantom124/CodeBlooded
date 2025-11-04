/**
 * @file SunflowerFactory.h
 * @brief Factory for creating Sunflower plant instances and configuring their monitors/states.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef SUNFLOWERFACTORY_H
#define SUNFLOWERFACTORY_H

#include "PlantFactory.h"
#include "PlantGrowthState.h"
#include "Plant.h"

class SunflowerFactory : public PlantFactory {
	public:
	/**
	 * @brief Construct a new SunflowerFactory which assigns monitors to created plants.
	 * @param waterMon Pointer to the WaterMonitor to attach to new Sunflower instances.
	 * @param fertMon Pointer to the FertilizerMonitor to attach to new Sunflower instances.
	 * @param deadMon Pointer to the DeadMonitor to attach to new Sunflower instances.
	 */
/**
 * @brief Execute the function's primary operation.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 */
		SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon);
		~SunflowerFactory();
		/**
		 * @brief Create a new Sunflower plant with default configuration and attached monitors.
		 * @return Plant* Newly allocated Sunflower instance (caller owns the pointer).
		 */
		Plant* createPlant();

		/**
		 * @brief (Optional) Create a Sunflower with a specific growth state and resource levels.
		 * @param state Initial growth state for the created Sunflower.
		 * @param waterLevel Initial water level (0-100).
		 * @param fertilizerLevel Initial fertilizer level (0-100).
		 * @return Plant* Newly allocated Sunflower configured with the provided state and levels.
		 */
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */
		// Plant* createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel);
};

#endif
