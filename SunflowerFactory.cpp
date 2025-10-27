#include "SunflowerFactory.h"
#include "Sunflower.h"

SunflowerFactory::SunflowerFactory(WaterMonitor* waterMon, FertilizerMonitor* fertMon, DeadMonitor* deadMon):PlantFactory(waterMon, fertMon, deadMon){}

SunflowerFactory::~SunflowerFactory(){}

Plant* SunflowerFactory::createPlant(){
    return new Sunflower();
}

// Plant* SunflowerFactory::createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     return new Sunflower(state, waterLevel, fertilizerLevel);
// }
