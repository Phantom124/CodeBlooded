#ifndef FERTILIZERMONITOR_H
#define FERTILIZERMONITOR_H

#include "PlantMonitor.h"

class Plant;

class FertilizerMonitor : public PlantMonitor {
public:
    FertilizerMonitor();
    ~FertilizerMonitor();
    void update(Plant* plant);
};

#endif // FERTILIZERMONITOR_H