#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "Item.h"
#include "Plant.h"
// #include "PlantComponent.h"
#include <vector>
#include <string>

class GreenHouseInventory {
    public:
        virtual ~GreenHouseInventory();

        // keep signature matching your implementation
        virtual void addPlant(Plant* plant) = 0;
        virtual void checkStockLevel();
        virtual std::vector<Plant*> getPlants();
        
        // declare restorePlants so Caretaker can call it
        virtual void restorePlants(const std::vector<PlantComponent*>& plants);

    protected:
        // storage used by the default implementation in GreenHouseInventory.cpp
        std::vector<Item> items;
        std::vector<Plant*> plants;
};

#endif