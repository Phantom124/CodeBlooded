#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantComponent.h"
#include "Plant.h"
#include "StaffHandler.h"
#include "Item.h"

#include <string>
#include <vector>
#include <map>

class GreenHouseInventory {
	private:
		std::vector<Plant*> plants;
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
		std::vector<Plant*> getPlants();
		void restorePlants(const std::vector<PlantComponent*>& plants);
};

#endif
