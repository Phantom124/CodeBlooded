#ifndef QUERYPRODUCT_H
#define QUERYPRODUCT_H

#include <string>
#include <vector>
#include <sstream>

#include "PlantGrowthState.h"
#include "Plant.h"
#include "RealGreenHouseInventory.h"

class RealGreenHouseInventory;

class QueryProduct{
    public:
        QueryProduct(RealGreenHouseInventory* inventory);
        ~QueryProduct();
        void setQueryProduct(std::string query);
        std::string getQuery();
        void execute();

        void executeSelect(std::string query);
        void executeInsert(std::string query);
        void executeDelete(std::string query);

    private:
        std::string query;
        RealGreenHouseInventory* inventory;

        // void inventorySelect(std::string query);
        // void inventoryInsert(std::string query);
        // void inventoryDelete(std::string query);
};

#endif