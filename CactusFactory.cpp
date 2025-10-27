#include "CactusFactory.h"

CactusFactory::CactusFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon):PlantFactory(waterMon, fertMon, deadMon){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
        throw std::invalid_argument("Monitors cannot be null");
    }
}

CactusFactory::~CactusFactory(){}

Plant* CactusFactory::createPlant(){
    Cactus* newCactus = new Cactus();
    newCactus->attachWaterMonitor(this->waterMonitor);
    newCactus->attachFertilizerMonitor(this->fertilizerMonitor);
    newCactus->attachDeadMonitor(this->deadMonitor);
    return newCactus;
}