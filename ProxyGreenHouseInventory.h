#ifndef PROXYGREENHOUSEINVENTORY_H
#define PROXYGREENHOUSEINVENTORY_H

#include "GreenHouseInventory.h"  // Must include full base class

#include "QueryProduct.h"
#include <string>

class Plant;
class Customer;
class StaffHandler;

#include "RealGreenHouseInventory.h"

class ProxyGreenHouseInventory : public GreenHouseInventory {
public:
    ProxyGreenHouseInventory();
    ~ProxyGreenHouseInventory();

    void handle(Query* query) ;
    void displayPlants() ;
    void hourHasPassed() ;
    void restorePlants(std::vector<PlantComponent*> plants);
    virtual PlantComponent* orderPlant(std::string id);

private:
    void insertPlant(Plant* plant);
    void deletePlant(Plant* plant);

private:
    GreenHouseInventory* realInventory;
};

#endif
