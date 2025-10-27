#ifndef WATERMONITOR_H
#define WATERMONITOR_H

#include "PlantMonitor.h"
class Plant; // Forward declaration

// WaterMonitor inherits from PlantMonitor and adds water-specific monitoring functionality.
class WaterMonitor : public PlantMonitor {
public:
    WaterMonitor();
    ~WaterMonitor();

    void update(Plant* plant);

};

#endif // WATERMONITOR_H