#ifndef PROXYGREENHOUSEINVENTORY_H
#define PROXYGREENHOUSEINVENTORY_H

#include "GreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "Item.h"

#include <string>

class ProxyGreenHouseInventory : public GreenHouseInventory {
    public:
        ProxyGreenHouseInventory(RealGreenHouseInventory* realInv, std::string type);
        ~ProxyGreenHouseInventory();
        
        void showPlant(std::string parameters);
        void showAllPlants();
        void addPlant(Item item);
        void removePlant(std::string parameters);
    
    private:
        RealGreenHouseInventory* realInventory;
        std::string userType;
};

#endif
