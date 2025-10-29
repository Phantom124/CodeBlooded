#include "GreenHouseInventory.h"
#include "Item.h"
#include "Plant.h"
#include "PlantComponent.h"
#include <vector>
#include <string>

GreenHouseInventory::~GreenHouseInventory(){
    for (Plant* p: this->plants){
        delete p;
    }
    this->plants.clear();
}

void GreenHouseInventory::addPlant(Plant *plant)
{
    // default behaviour: store the item in the inventory container if one exists.
    // If derived classes maintain their own storage, they can override this.
    if (plant != nullptr) this->plants.push_back(plant);
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
