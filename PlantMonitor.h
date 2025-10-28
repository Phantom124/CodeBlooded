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

    void setStaffSystem(StaffSystem* staffSystem);
    virtual void update(Plant* plant) = 0;  // Pure virtual function
};

#endif // PLANTMONITOR_H