#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H

#include "PlantComponent.h"
#include "PlantSnapshot.h"
#include "Item.h"
#include <vector>
#include <string>
#include "QueryProduct.h"

#include "Order.h"

class Plant;

class GreenHouseInventory {
    public:
        virtual ~GreenHouseInventory();

        // virtual void addPlant(Plant* plant) = 0;
        // virtual void checkStockLevel();
        // virtual std::vector<Plant*> getPlants() = 0;
        // virtual void removePlant(std::string parameters) = 0;
        
        // declare restorePlants so Caretaker can call it
        virtual void restorePlants(std::vector<PlantComponent*> plants) = 0;

        virtual void hourHasPassed() = 0;
        
        // virtual void printPlant();
        // virtual void handle(Order* order) = 0;
        virtual void handle(Query* query) = 0;
        virtual void insertPlant(Plant* plant) = 0;
        virtual void deletePlant(Plant* plant) = 0;
        virtual void displayPlants() = 0;

    protected:
        // storage used by the default implementation in GreenHouseInventory.cpp
        
};
 
#endif // GREENHOUSEINVENTORY_H