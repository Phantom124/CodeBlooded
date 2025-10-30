#ifndef PROXYGREENHOUSEINVENTORY_H
#define PROXYGREENHOUSEINVENTORY_H

#include "GreenHouseInventory.h"
// #include "RealGreenHouseInventory.h"
// #include "QueryProduct.h"
// #include "Customer.h"
// #include "StaffHandler.h"
#include "Item.h"

class RealGreenHouseInventory;
class QueryProduct;
class Plant;
class Customer;
class StaffHandler;

#include <string>
// #include <typeinfo>

class ProxyGreenHouseInventory : public GreenHouseInventory {
    public:
        ProxyGreenHouseInventory();
        ~ProxyGreenHouseInventory();
        
        void showPlant(std::string parameters);
        void showAllPlants();
        void addPlant(Plant* plant);
        void removePlant(std::string parameters);

        void handleControlRights(void* user, QueryProduct query);
    
    private:
        RealGreenHouseInventory* realInventory;
};

#endif

//typeid to validate
//void* => generic pointer, can point to any data type
