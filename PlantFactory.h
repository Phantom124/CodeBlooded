#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"
#include "GreenHouseInventory.h"

class PlantFactory {
    public:
        PlantFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* proxyInventory);
        virtual Plant* createPlant() = 0;
        virtual ~PlantFactory() {}
    protected:
        WaterMonitor* waterMonitor;
        FertilizerMonitor* fertilizerMonitor;
        DeadMonitor* deadMonitor;
        QueryBuilder* queryBuilder;
        GreenHouseInventory* proxyInventory;
        void sendInsertQuery(Plant* plant);
};

#endif