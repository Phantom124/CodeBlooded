#ifndef REALGREENHOUSEINVENTORY_H
#define REALGREENHOUSEINVENTORY_H

#include "PlantComponent.h"
#include "Plant.h"
#include <string>
#include <vector>
#include <map>

class RealGreenHouseInventory {
	private:
		std::vector<Plant*> plants;
		int totalPlants;
		std::map<std::string, int> plantCountByType;

	public:
		void addPlant(Plant* plant);
		void checkStockLevel();
		std::vector<Plant*> getPlants();
		void restorePlants(std::vector<PlantComponent*> plants);
};

#endif
