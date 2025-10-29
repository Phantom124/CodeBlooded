#include "GreenHouseInventory.h"
#include "Item.h"
#include "Plant.h"
#include "PlantComponent.h"
#include <vector>
#include <string>

void GreenHouseInventory::addPlant(Item item) {
    // default behaviour: store the item in the inventory container if one exists.
    // If derived classes maintain their own storage, they can override this.
    this->items.push_back(item);
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
        Item item(std::to_string(plant->getPlantId()), plant->getName(), plant->getMaturityStateName());
        addPlant(item);
    }
}