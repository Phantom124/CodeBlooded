/**
 * @file SunflowerFactory.cpp
 * @brief SunflowerFactory.cpp — Header and declarations for the SunflowerFactory.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "SunflowerFactory.h"
#include "Sunflower.h"
#include <stdexcept>

SunflowerFactory::SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon)
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 * @param nullptr The nullptr parameter used by the function.
 */

    : PlantFactory(waterMon, fertMon, deadMon, nullptr){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param null" TODO - describe parameter
 */

        throw std::invalid_argument("Monitors cannot be null");
    }
}

SunflowerFactory::~SunflowerFactory(){}

Plant* SunflowerFactory::createPlant(){
    Sunflower* newSunflower = new Sunflower();
/**
 * @brief Execute the function's primary operation.
 * @param this->waterMonitor TODO - describe parameter
 */

    newSunflower->attachWaterMonitor(this->waterMonitor);
/**
 * @brief Execute the function's primary operation.
 * @param this->fertilizerMonitor TODO - describe parameter
 */

    newSunflower->attachFertilizerMonitor(this->fertilizerMonitor);
/**
 * @brief Execute the function's primary operation.
 * @param this->deadMonitor TODO - describe parameter
 */

    newSunflower->attachDeadMonitor(this->deadMonitor);

    if (this->queryBuilder != nullptr){
/**
 * @brief Execute the function's primary operation.
 * @param newSunflower The newSunflower parameter used by the function.
 */

        this->queryBuilder->insertQueryBuilder(newSunflower);
    }
    
    return  newSunflower;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

// Plant* SunflowerFactory::createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){


//     return new Sunflower(state, waterLevel, fertilizerLevel);
// }
