#ifndef GREENHOUSEFACADE_H
#define GREENHOUSEFACADE_H

#include "RealGreenHouseInventory.h"
#include "PlantFactory.h"
#include "PlantMonitor.h"
#include "StaffHandler.h"
#include "Plant.h"
#include <string>

class GreenHouseFacade {
    private:
        RealGreenHouseInventory* inventory;
        PlantFactory* factory;
        PlantMonitor* monitor;
        StaffHandler* staff;

    public:
        GreenHouseFacade();
        ~GreenHouseFacade();
        Plant* createPlant(std::string plantType);
        void addPlantToInventory(Plant* plant);
        void monitorPlants();
        void handlePlant();
};

#endif