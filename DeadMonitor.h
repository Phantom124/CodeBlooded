
#ifndef DEADMONITOR_H
#define DEADMONITOR_H

#include "PlantMonitor.h"
#include "StaffSystem.h"
#include "Plant.h"

class DeadMonitor : public PlantMonitor {
public:
    DeadMonitor();
    ~DeadMonitor();
    void update(Plant* plant);
private:
    StaffSystem* staffSystem;
    std::string type;
};

#endif // DEADMONITOR_H
