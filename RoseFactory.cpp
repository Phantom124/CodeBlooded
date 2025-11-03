#include "RoseFactory.h"
#include "Rose.h"
#include <stdexcept>

RoseFactory::RoseFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon) : PlantFactory(waterMon, fertMon, deadMon, queryBuilder)
{
    if (waterMon == nullptr || fertMon == nullptr || deadMon == nullptr)
    {
        throw std::invalid_argument("Monitors cannot be null");
    }
}

RoseFactory::~RoseFactory(){
}

Plant *RoseFactory::createPlant()
{
    Rose *newRose = new Rose();
    newRose->attachWaterMonitor(this->waterMonitor);
    newRose->attachFertilizerMonitor(this->fertilizerMonitor);
    newRose->attachDeadMonitor(this->deadMonitor);

    this->queryBuilder->insertQueryBuilder(newRose);

    return newRose;
}

// Plant* RoseFactory::createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     return new Rose(state, waterLevel, fertilizerLevel);
// }