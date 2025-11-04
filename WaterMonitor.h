/**
 * @file WaterMonitor.h
 * @brief Header for WaterMonitor: observes plant hydration and creates WaterCommand objects when needed.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef WATERMONITOR_H
#define WATERMONITOR_H

#include "PlantMonitor.h"
#include "WaterCommand.h"
class Plant; // Forward declaration

// WaterMonitor inherits from PlantMonitor and adds water-specific monitoring functionality.
class WaterMonitor : public PlantMonitor {
public:
    WaterMonitor();
    ~WaterMonitor();

/**
 * @brief Receive notifications from a Plant and handle hydration-related checks.
 * @param plant Pointer to the Plant that triggered the notification.
 */
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */
     void update(Plant* plant);

};

#endif // WATERMONITOR_H
