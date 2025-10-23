#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantSnapshot.h"
#include "Plant.h"
#include "StaffHandler.h"
#include <string>
#include <vector>
#include <map>

class GreenHouseInventory {
	private:
		std::vector<Plant*> plants;
		std::vector<StaffHandler*> staffhandlers;
		int totalPlants;
		std::map<std::string, int> plantCountByType;

	public:
		void notify(std::string msg, std::string handlerType);
		void registerStaffhandler(StaffHandler* handler);
		void addPlant(Plant* plant, StaffHandler* staff);
		void removePlant(std::string plantType, StaffHandler* staff);
		void requestPlant(std::string plantType, StaffHandler* staff);
		void checkStockLevel();
		Plant* getPlant(std::string plantType);
		PlantSnapshot* createSnapshot();
		std::vector<Plant*> getPlants();
};

#endif
