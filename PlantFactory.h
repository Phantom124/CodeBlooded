/**
 * @file PlantFactory.h
 * @brief PlantFactory.h — Header and declarations for the PlantFactory.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class PlantFactory {
    public:
/**
 * @brief Execute the function's primary operation.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 * @param queryBuilder The queryBuilder parameter used by the function.
 */

        PlantFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder);
        virtual Plant* createPlant() = 0;
        virtual ~PlantFactory();
    protected:
        WaterMonitor* waterMonitor;
        FertilizerMonitor* fertilizerMonitor;
        DeadMonitor* deadMonitor;
        QueryBuilder* queryBuilder;
        bool ownsQueryBuilder;
};

#endif
