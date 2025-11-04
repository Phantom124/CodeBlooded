/**
 * @file PlantMonitor.cpp
 * @brief PlantMonitor.cpp — Header and declarations for the PlantMonitor.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "PlantMonitor.h"
#include "Plant.h"
#include <stdexcept>

PlantMonitor::PlantMonitor()
{
    staffSystem = nullptr;
}

PlantMonitor::~PlantMonitor()
{
    staffSystem = nullptr;
}

void PlantMonitor::setStaffSystem(StaffSystem *staffSystem)
{
    if (staffSystem != nullptr)
    {
        this->staffSystem = staffSystem;
    }
    // else{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param null
 */

    //     throw std::invalid_argument("StaffSystem cannot be null");
    // }
}
