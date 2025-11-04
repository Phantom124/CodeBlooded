/**
 * @file CactusFactory.cpp
 * @brief CactusFactory.cpp — Header and declarations for the CactusFactory.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "CactusFactory.h"
#include <stdexcept>

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 * @param nullptr The nullptr parameter used by the function.
 */
CactusFactory::CactusFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon)

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

CactusFactory::~CactusFactory(){}

/**
 * @brief Execute the function's primary operation.
 * @param this->waterMonitor
 */

 /**
 * @brief Execute the function's primary operation.
 * @param this->fertilizerMonitor
 */

/**
 * @brief Execute the function's primary operation.
 * @param this->deadMonitor
 */

 /**
 * @brief Execute the function's primary operation.
 * @param newCactus The newCactus parameter used by the function.
 */
Plant* CactusFactory::createPlant(){
    Cactus* newCactus = new Cactus();
    newCactus->attachWaterMonitor(this->waterMonitor);
    newCactus->attachFertilizerMonitor(this->fertilizerMonitor);
    newCactus->attachDeadMonitor(this->deadMonitor);

    if (this->queryBuilder != nullptr){
        this->queryBuilder->insertQueryBuilder(newCactus);
    }

    return newCactus;
}
