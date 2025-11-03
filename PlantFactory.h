#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class PlantFactory {
    public:
        PlantFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder);
        virtual Plant* createPlant() = 0;
        virtual ~PlantFactory() {}
    protected:
        WaterMonitor* waterMonitor;
        FertilizerMonitor* fertilizerMonitor;
        DeadMonitor* deadMonitor;
        QueryBuilder* queryBuilder;
};

#endif