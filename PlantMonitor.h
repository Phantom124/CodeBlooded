#ifndef PLANTMONITOR_H
#define PLANTMONITOR_H

#include "StaffHandler.h"  // or forward declare if not needed
#include <string>

// Forward declaration
class Plant;

class PlantMonitor {
protected:
    StaffHandler* chain;
    std::string type;

public:
    PlantMonitor();
    virtual ~PlantMonitor();
    
    void setChain(StaffHandler* chain);
    virtual void update(Plant* plant) = 0;  // Pure virtual function
};

#endif // PLANTMONITOR_H