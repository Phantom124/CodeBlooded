#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantComponent.h"
#include "PlantSnapshot.h"
#include "Item.h"
#include <vector>
#include <string>

class Plant;

class GreenHouseInventory {
    public:
        virtual ~GreenHouseInventory();

        virtual void addPlant(Plant* plant) = 0;
        virtual void checkStockLevel();
        virtual std::vector<Plant*> getPlants();
        virtual void removePlant(std::string parameters) = 0;
        
        // declare restorePlants so Caretaker can call it
        virtual void restorePlants(const std::vector<PlantComponent*>& plants);

    protected:
        // storage used by the default implementation in GreenHouseInventory.cpp
        // std::vector<Item> items;
        std::vector<Plant*> plants;
};

#endif