/**
 * @file GreenHouseInventory.cpp
 * @brief GreenHouseInventory.cpp — Header and declarations for the GreenHouseInventory.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "GreenHouseInventory.h"
#include "Item.h"
#include "Plant.h"
#include "PlantComponent.h"
#include <vector>
#include <string>
#include <iostream>

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

/**
 * @brief Execute the function's primary operation.
 * @param plants The plants parameter used by the function.
 */

void GreenHouseInventory::restorePlants(const std::vector<PlantComponent*>& plants) {
    for (PlantComponent* pc : plants) {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param pc The pc parameter used by the function.
 */

        Plant* plant = dynamic_cast<Plant*>(pc);
        if (!plant) continue;
        // Construct Item from Plant fields (Item has constructor Item(string id, string type, string maturity))
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param std::to_string(plant->getPlantId()) 
 * @param plant->getName()
 * @param plant->getMaturityStateName() 
 */

        // Item item(std::to_string(plant->getPlantId()), plant->getName(), plant->getMaturityStateName());
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

        addPlant(plant);
    }
}

void GreenHouseInventory::printPlant(){
    if (this->plants.empty()){
        std::cout << "No plants in the Inventory." << std::endl;
        return;
    }

    for (auto p: this->plants){
        if (!p){
            continue;
        }
        p->printPlant();
    }
}
