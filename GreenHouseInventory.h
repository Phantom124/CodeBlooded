#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantSnapshot.h"
#include "Plant.h"
#include "StaffHandler.h"
#include "Item.h"

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

		virtual void addPlant(Item item) = 0;
		virtual void removePlant(std::string query) = 0;
		virtual void showPlant(std::string query) = 0;
    	virtual void showAllPlants() = 0;
        // virtual void handleControlRights(void* user, QueryProduct query) = 0;

		
		void requestPlant(std::string plantType, StaffHandler* staff);
		void checkStockLevel();
		Plant* getPlant(std::string plantType);
		PlantSnapshot* createSnapshot();
		std::vector<Plant*> getPlants();
};

#endif
