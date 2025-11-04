/**
 * @file PlantSnapshot.h
 * @brief PlantSnapshot.h — Header and declarations for the PlantSnapshot.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef PLANTSNAPSHOT_H
#define PLANTSNAPSHOT_H

#include "Plant.h"
#include <string>
#include "Cactus.h"
#include "Rose.h"
#include "Sunflower.h"

class PlantSnapshot {
	private:
		std::string plantType;
		int careCount;
		int waterLevel;
		int fertilizerLevel;
		std::string growthStateName;

	public:
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

		PlantSnapshot(Plant* plant);
		Plant* convertToPlant();
};

#endif
