/**
 * @file FertilizerMonitor.h
 * @brief FertilizerMonitor.h — Header and declarations for the FertilizerMonitor.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef FERTILIZERMONITOR_H
#define FERTILIZERMONITOR_H

#include "PlantMonitor.h"

class Plant;

class FertilizerMonitor : public PlantMonitor {
public:
    FertilizerMonitor();
    ~FertilizerMonitor();
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

    void update(Plant* plant);
};

#endif // FERTILIZERMONITOR_H
