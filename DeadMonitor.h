/**
 * @file DeadMonitor.h
 * @brief DeadMonitor.h — Header and declarations for the DeadMonitor.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef DEADMONITOR_H
#define DEADMONITOR_H

#include "PlantMonitor.h"

#include "Plant.h"

class DeadMonitor : public PlantMonitor {
public:
    DeadMonitor();
    ~DeadMonitor();
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

    void update(Plant* plant);
};

#endif // DEADMONITOR_H
