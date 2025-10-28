#include "GreenHouseInventory.h"

void GreenHouseInventory::addPlant(Plant* plant) {
    plants.push_back(plant);
    totalPlants++;
    plantCountByType[plant->getType()]++;
}

void GreenHouseInventory::checkStockLevel() {};

std::vector<Plant*> GreenHouseInventory::getPlants() {
    return plants;
}

void GreenHouseInventory::restorePlants(const std::vector<PlantComponent*>& plantComponents) {
    for (auto& pc : plantComponents) {
        Plant* plant = dynamic_cast<Plant*>(pc);
        if (plant) {
            addPlant(plant);
        }
    }
}