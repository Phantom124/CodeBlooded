/**
 * @file GreenHouseInventory.h
 * @brief GreenHouseInventory.h — Header and declarations for the GreenHouseInventory.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plants The plants parameter used by the function.
 */

        virtual void restorePlants(const std::vector<PlantComponent*>& plants);

        virtual void hourHasPassed() = 0;
        
        virtual void printPlant();

    protected:
        // storage used by the default implementation in GreenHouseInventory.cpp
        std::vector<Plant*> plants;
};

#endif
