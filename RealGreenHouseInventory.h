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
        ~RealGreenHouseInventory();

        void showPlant(std::string parameters);
        void showAllPlants();
        void addPlant(Item item);
        void removePlant(std::string parameters);

    private:
        std::vector<Item> plant;
};

#endif