#ifndef QUERYPRODUCT_H
#define QUERYPRODUCT_H

#include <string>
#include <vector>
#include <sstream>

#include "PlantGrowthState.h"
#include "Plant.h"
// #include "GreenHouseInventory.h"
// #include "ProxyGreenHouseInventory.h"
#include "Rose.h"
#include "Sunflower.h"
#include "Cactus.h"
#include "SeedState.h"

class GreenHouseInventory;
class ProxyGreenHouseInventory;

class Query{
    public:
        Query();
        ~Query();

        void setOriginator(std::string originator);
        std::string getOriginator();
        void setOperation(std::string operation);
        std::string getOperation();
        void setPlant(Plant* plant);
        Plant* getPlant();

    private:
        std::string originator;
        std::string operation;
        Plant* plant;
};

#endif