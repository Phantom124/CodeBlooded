#include "SunflowerFactory.h"
#include "Sunflower.h"

SunflowerFactory::SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* greenHouse):PlantFactory(waterMon, fertMon, deadMon, queryBuilder, greenHouse){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr || queryBuilder == nullptr || greenHouse == nullptr){
        throw std::invalid_argument("Monitors and Inventory cannot be null");
    }
}

SunflowerFactory::~SunflowerFactory(){}

Plant* SunflowerFactory::createPlant(){
    Sunflower* newSunflower = new Sunflower();
    newSunflower->attachWaterMonitor(this->waterMonitor);
    newSunflower->attachFertilizerMonitor(this->fertilizerMonitor);
    newSunflower->attachDeadMonitor(this->deadMonitor);

    this->sendInsertQuery(newSunflower);
    
    return newSunflower;
}

// Plant* SunflowerFactory::createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     return new Sunflower(state, waterLevel, fertilizerLevel);
// }
