/**
 * @file RealGreenHouseInventory.h
 * @brief RealGreenHouseInventory.h — Header and declarations for the RealGreenHouseInventory.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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

/**
 * @brief Execute the function's primary operation.
 * @param parameters The parameters parameter used by the function.
 */

        void showPlant(std::string parameters);
        void showAllPlants();
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

        void addPlant(Plant* plant);


        void removePlant(std::string parameters);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param user The user parameter used by the function.
 * @param query The query parameter used by the function.
 */

        // void handleControlRights(void* user, QueryProduct query);

        void hourHasPassed();
        std::vector<Plant*> getAllPlants();

        void printPlant();


    private:
        // std::vector<Plant*> plant;
};

#endif
