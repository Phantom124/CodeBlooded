#include "GreenHouseInventory.h"

void GreenHouseInventory::addPlant(Plant* plant) {
    plants.push_back(plant);
    totalPlants++;
    plantCountByType[plant->getName()]++;
}

void GreenHouseInventory::checkStockLevel() {};

std::vector<Plant*> GreenHouseInventory::getPlants() {
    return plants;
}

void GreenHouseInventory::restorePlants(const std::vector<PlantSnapshot*>& snapshots) {
    for (auto& snapshot : snapshots) {
        Plant* plant = snapshot->convertToPlant();
        if (plant) {
            addPlant(plant);
        }
    }
}
