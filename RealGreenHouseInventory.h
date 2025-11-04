#ifndef REALGREENHOUSEINVENTORY_H
#define REALGREENHOUSEINVENTORY_H

#include <string>
#include <vector>
#include <iostream>

#include "Plant.h"
#include "Item.h"
#include "GreenHouseInventory.h"
#include "QueryProduct.h"

class RealGreenHouseInventory : public GreenHouseInventory{
    public:
        RealGreenHouseInventory();
        virtual ~RealGreenHouseInventory();

        void showPlant(std::string parameters);
        void showAllPlants();
        void addPlant(Plant* plant);
        void removePlant(std::string parameters);
        // void handleControlRights(void* user, QueryProduct query);

        void hourHasPassed();
        std::vector<Plant*> getAllPlants();

        void printPlant();
        friend class ProxyGreenHouseInventory;

        virtual void handle(Query* query);
    private://We do not want these to be called by anyone but Proxy
        virtual void insertPlant(Plant* plant);
        virtual void deletePlant(Plant* plant);
        virtual void displayPlants();
        // virtual void hourHasPassed();
        virtual void restorePlants(std::vector<PlantComponent*> plants);
        

    private:
        // std::vector<Plant*> plant;
        std::vector<Plant*> plants;
};

#endif