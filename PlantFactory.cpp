#include "PlantFactory.h"

PlantFactory::PlantFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
        throw std::invalid_argument("Monitors cannot be null");
    }
    this->waterMonitor = waterMon;
    this->fertilizerMonitor = fertMon;
    this->deadMonitor = deadMon;
}