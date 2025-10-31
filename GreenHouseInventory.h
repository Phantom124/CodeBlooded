#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantComponent.h"
#include "PlantSnapshot.h"
#include "Item.h"
#include "Plant.h"
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

        virtual void hourHasPassed() = 0;

    protected:
        // storage used by the default implementation in GreenHouseInventory.cpp
        std::vector<Plant*> plants;
};

#endif