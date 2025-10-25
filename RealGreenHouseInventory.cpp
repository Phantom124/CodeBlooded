#include "RealGreenHouseInventory.h"

void RealGreenHouseInventory::addPlant(Plant* plant) {
    plants.push_back(plant);
    totalPlants++;
    plantCountByType[plant->getType()]++;
}

void RealGreenHouseInventory::checkStockLevel() {};

std::vector<Plant*> RealGreenHouseInventory::getPlants() {
    return plants;
}

void RealGreenHouseInventory::restorePlants(std::vector<PlantComponent*> plantComponents) {
    for (auto& pc : plantComponents) {
        Plant* plant = dynamic_cast<Plant*>(pc);
        if (plant) {
            addPlant(plant);
        }
    }
}