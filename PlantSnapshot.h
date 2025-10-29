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

	public:
		PlantSnapshot(Plant* plant);
		Plant* convertToPlant();
};

#endif
