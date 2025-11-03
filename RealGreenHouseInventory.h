#ifndef REALGREENHOUSEINVENTORY_H
#define REALGREENHOUSEINVENTORY_H

#include <string>
#include <vector>
#include <iostream>

#include "Plant.h"
#include "Item.h"
#include "GreenHouseInventory.h"

class RealGreenHouseInventory : public GreenHouseInventory{
    public:
        RealGreenHouseInventory();
        virtual ~RealGreenHouseInventory();

        void showPlant(std::string parameters);
        void showAllPlants();
        void addPlant(Plant* plant);
        void removePlant(std::string parameters);
        // void handleControlRights(void* user, QueryProduct query);

        void hourHasPassed();
        std::vector<Plant*> getAllPlants();

        void printPlant();


    private:
        // std::vector<Plant*> plant;
};

#endif