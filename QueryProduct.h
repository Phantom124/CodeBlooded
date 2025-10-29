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
        QueryProduct(ProxyGreenHouseInventory* inventory);
        ~QueryProduct();
        void setQueryProduct(std::string query);
        std::string getQuery();
        void execute();

        void executeSelect(std::string query);
        void executeInsert(std::string query);
        void executeDelete(std::string query);

    private:
        std::string query;
        ProxyGreenHouseInventory* inventory;
        Plant* plant;
};

#endif