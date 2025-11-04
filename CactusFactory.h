#ifndef CACTUSFACTORY_H
#define CACTUSFACTORY_H

#include "PlantFactory.h"
#include "Cactus.h"

class CactusFactory : public PlantFactory {
public:
    CactusFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* greenHouse);
    ~CactusFactory();
    Plant* createPlant();
    //Parameterized constructor version
    // Plant* createPlant(PlantGrowthState* state, int waterLevel, int fertilizerLevel);

};

#endif // CACTUSFACTORY_H