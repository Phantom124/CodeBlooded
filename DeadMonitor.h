#ifndef DEADMONITOR_H
#define DEADMONITOR_H

#include "PlantMonitor.h"

#include "Plant.h"

class DeadMonitor : public PlantMonitor {
public:
    DeadMonitor();
    ~DeadMonitor();
    void update(Plant* plant);
};

#endif // DEADMONITOR_H