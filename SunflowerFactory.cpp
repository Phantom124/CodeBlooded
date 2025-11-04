#include "SunflowerFactory.h"
#include "Sunflower.h"
#include <stdexcept>

SunflowerFactory::SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon)
    : PlantFactory(waterMon, fertMon, deadMon, nullptr){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
        throw std::invalid_argument("Monitors cannot be null");
    }
}

SunflowerFactory::~SunflowerFactory(){}

Plant* SunflowerFactory::createPlant(){
    Sunflower* newSunflower = new Sunflower();
    newSunflower->attachWaterMonitor(this->waterMonitor);
    newSunflower->attachFertilizerMonitor(this->fertilizerMonitor);
    newSunflower->attachDeadMonitor(this->deadMonitor);

    if (this->queryBuilder != nullptr){
        this->queryBuilder->insertQueryBuilder(newSunflower);
    }
    
    return  newSunflower;
}

// Plant* SunflowerFactory::createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     return new Sunflower(state, waterLevel, fertilizerLevel);
// }
