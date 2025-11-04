/**
 * @file QueryProduct.h
 * @brief QueryProduct.h — Header and declarations for the QueryProduct.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef QUERYPRODUCT_H
#define QUERYPRODUCT_H

#include <string>
#include <vector>
#include <sstream>

#include "PlantGrowthState.h"
#include "Plant.h"
#include "GreenHouseInventory.h"
#include "ProxyGreenHouseInventory.h"
#include "Rose.h"
#include "Sunflower.h"
#include "Cactus.h"
#include "SeedState.h"

class GreenHouseInventory;
class ProxyGreenHouseInventory;

class QueryProduct{
    public:
/**
 * @brief Execute the function's primary operation.
 * @param inventory The inventory parameter used by the function.
 */

        QueryProduct(ProxyGreenHouseInventory* inventory);
        ~QueryProduct();
/**
 * @brief Execute the function's primary operation.
 * @param query The query parameter used by the function.
 */

        void setQueryProduct(std::string query);
        std::string getQuery();
        void execute();


        void executeSelect(std::string query);


        void executeInsert(std::string query);


        void executeDelete(std::string query);

    private:
        std::string query;
        ProxyGreenHouseInventory* inventory;
        // Plant* plant;
};

#endif
