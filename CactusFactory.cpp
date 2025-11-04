#include "CactusFactory.h"

CactusFactory::CactusFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* greenHouse):PlantFactory(waterMon, fertMon, deadMon, queryBuilder, greenHouse){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr || queryBuilder == nullptr || greenHouse == nullptr){
        throw std::invalid_argument("Monitors and Inventory cannot be null");
    }
}

CactusFactory::~CactusFactory(){}

Plant* CactusFactory::createPlant(){
    Cactus* newCactus = new Cactus();
    newCactus->attachWaterMonitor(this->waterMonitor);
    newCactus->attachFertilizerMonitor(this->fertilizerMonitor);
    newCactus->attachDeadMonitor(this->deadMonitor);

    this->sendInsertQuery(newCactus);
    // this->queryBuilder->insertQueryBuilder(newCactus);

    return newCactus;
}