#ifndef FERTILIZERMONITOR_H
#define FERTILIZERMONITOR_H

#include "PlantMonitor.h"
#include "StaffSystem.h"

class Plant;

class FertilizerMonitor : public PlantMonitor {
public:
    FertilizerMonitor();
    ~FertilizerMonitor();
    void update(Plant* plant);

private:
    StaffSystem* staffSystem;
    std::string type;
};

#endif // FERTILIZERMONITOR_H