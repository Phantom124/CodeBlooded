#include "PlantMonitor.h"
#include "Plant.h"

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
    //     throw std::invalid_argument("StaffSystem cannot be null");
    // }
}
