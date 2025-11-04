#include "RoseFactory.h"
#include "Rose.h"
#include <stdexcept>

RoseFactory::RoseFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* greenHouse) : PlantFactory(waterMon, fertMon, deadMon, queryBuilder, greenHouse)
{
    if (waterMon == nullptr || fertMon == nullptr || deadMon == nullptr || queryBuilder == nullptr || greenHouse == nullptr)
    {
        throw std::invalid_argument("Monitors and Inventory cannot be null");
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
    // std::cout << "NEW ROSE CREATED => " << newRose->getPlantId() << " " << newRose->getName() << " " << newRose->getMaturityStateName() << std::endl;
    this->sendInsertQuery(newRose);
    // this->queryBuilder->insertQueryBuilder(newRose);

    return newRose;
}

// Plant* RoseFactory::createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     return new Rose(state, waterLevel, fertilizerLevel);
// }