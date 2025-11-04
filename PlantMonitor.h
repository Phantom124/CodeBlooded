/**
 * @file PlantMonitor.h
 * @brief PlantMonitor.h — Header and declarations for the PlantMonitor.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef PLANTMONITOR_H
#define PLANTMONITOR_H

#include "StaffHandler.h"  // or forward declare if not needed
#include <string>
#include "StaffSystem.h"


// Forward declaration
class Plant;


class PlantMonitor {
protected:
    StaffSystem* staffSystem;
    std::string type;

public:
    PlantMonitor();
    virtual ~PlantMonitor();

/**
 * @brief Execute the function's primary operation.
 * @param staffSystem The staffSystem parameter used by the function.
 */

    void setStaffSystem(StaffSystem* staffSystem);
    virtual void update(Plant* plant) = 0;  // Pure virtual function
};

#endif // PLANTMONITOR_H
