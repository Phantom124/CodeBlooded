/**
 * @file RoseFactory.cpp
 * @brief RoseFactory.cpp — Header and declarations for the RoseFactory.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "RoseFactory.h"
#include "Rose.h"
#include <stdexcept>

RoseFactory::RoseFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon)
    : PlantFactory(waterMon, fertMon, deadMon, nullptr)
{
    if (waterMon == nullptr || fertMon == nullptr || deadMon == nullptr)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param null" TODO - describe parameter
 */

        throw std::invalid_argument("Monitors cannot be null");
    }
}

RoseFactory::~RoseFactory(){
}

Plant *RoseFactory::createPlant()
{
    Rose *newRose = new Rose();
/**
 * @brief Execute the function's primary operation.
 * @param this->waterMonitor TODO - describe parameter
 */

    newRose->attachWaterMonitor(this->waterMonitor);
/**
 * @brief Execute the function's primary operation.
 * @param this->fertilizerMonitor TODO - describe parameter
 */

    newRose->attachFertilizerMonitor(this->fertilizerMonitor);
/**
 * @brief Execute the function's primary operation.
 * @param this->deadMonitor TODO - describe parameter
 */

    newRose->attachDeadMonitor(this->deadMonitor);

    if (this->queryBuilder != nullptr){
/**
 * @brief Execute the function's primary operation.
 * @param newRose The newRose parameter used by the function.
 */

        this->queryBuilder->insertQueryBuilder(newRose);  
    }

    return newRose;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

// Plant* RoseFactory::createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){


//     return new Rose(state, waterLevel, fertilizerLevel);
// }
