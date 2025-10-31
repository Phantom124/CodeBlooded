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

void GreenHouseInventory::restorePlants(const std::vector<PlantComponent*>& plants) {
    for (PlantComponent* pc : plants) {
        Plant* plant = dynamic_cast<Plant*>(pc);
        if (!plant) continue;
        // Construct Item from Plant fields (Item has constructor Item(string id, string type, string maturity))
        // Item item(std::to_string(plant->getPlantId()), plant->getName(), plant->getMaturityStateName());
        addPlant(plant);
    }
}