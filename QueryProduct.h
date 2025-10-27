#ifndef QUERYPRODUCT_H
#define QUERYPRODUCT_H

#include <string>
#include <vector>
#include <sstream>

#include "PlantGrowthState.h"
#include "Plant.h"
#include "GreenHouseInventory.h"

class GreenHouseInventory;

class QueryProduct{
    public:
        QueryProduct(GreenHouseInventory* inventory);
        ~QueryProduct();
        void setQueryProduct(std::string query);
        std::string getQuery();
        void execute();

        void executeSelect(std::string query);
        void executeInsert(std::string query);
        void executeDelete(std::string query);

    private:
        std::string query;
        GreenHouseInventory* inventory;

        // void inventorySelect(std::string query);
        // void inventoryInsert(std::string query);
        // void inventoryDelete(std::string query);
};

#endif