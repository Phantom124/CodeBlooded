#ifndef WATERMONITOR_H
#define WATERMONITOR_H

#include "PlantMonitor.h"
#include "WaterCommand.h"
#include "StaffSystem.h"

class Plant; // Forward declaration

// WaterMonitor inherits from PlantMonitor and adds water-specific monitoring functionality.
class WaterMonitor : public PlantMonitor {
public:
    WaterMonitor();
    ~WaterMonitor();

    void update(Plant* plant);

private:
    StaffSystem* staffSystem;
    std::string type;
};

#endif // WATERMONITOR_H