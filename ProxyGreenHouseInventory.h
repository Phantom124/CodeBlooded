/**
 * @file ProxyGreenHouseInventory.h
 * @brief ProxyGreenHouseInventory.h — Header and declarations for the ProxyGreenHouseInventory.h component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

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
        std::vector<Plant*> getPlants();

/**
 * @brief Execute the function's primary operation.
 * @param user The user parameter used by the function.
 * @param query The query parameter used by the function.
 */

        void handleControlRights(void* user, QueryProduct query);

        void hourHasPassed();

        void printPlant();
    
    private:
        RealGreenHouseInventory* realInventory;
};

#endif

//typeid to validate
//void* => generic pointer, can point to any data type
