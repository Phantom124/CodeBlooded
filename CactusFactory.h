/**
 * @file CactusFactory.h
 * @brief CactusFactory.h — Header and declarations for the CactusFactory.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef CACTUSFACTORY_H
#define CACTUSFACTORY_H

#include "PlantFactory.h"
#include "Cactus.h"

class CactusFactory : public PlantFactory {
public:
/**
 * @brief Execute the function's primary operation.
 * @param waterMon The waterMon parameter used by the function.
 * @param fertMon The fertMon parameter used by the function.
 * @param deadMon The deadMon parameter used by the function.
 */
    CactusFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon);
    ~CactusFactory();
    Plant* createPlant();
    //Parameterized constructor version
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */
    // Plant* createPlant(PlantGrowthState* state, int waterLevel, int fertilizerLevel);

};

#endif // CACTUSFACTORY_H
