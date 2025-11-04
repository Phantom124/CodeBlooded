#include "PlantFactory.h"

PlantFactory::PlantFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon, QueryBuilder* queryBuilder, GreenHouseInventory* proxyInventory){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr || queryBuilder == nullptr || proxyInventory == nullptr){
        throw std::invalid_argument("Monitors and Inventory cannot be null");
    }
    this->waterMonitor = waterMon;
    this->fertilizerMonitor = fertMon;
    this->deadMonitor = deadMon;
    this->queryBuilder = queryBuilder;
    this->proxyInventory = proxyInventory;
}

void PlantFactory::sendInsertQuery(Plant *plant){
    if(plant == nullptr){
        throw std::invalid_argument("PlantFactory::sendInsertQuery received a null Plant pointer");
    }
    if(this->queryBuilder == nullptr){
        throw std::runtime_error("PlantFactory::sendInsertQuery has no QueryBuilder assigned");
    }

    this->queryBuilder->createNewQuery();
    this->queryBuilder->buildOriginator("PlantFactory");
    this->queryBuilder->buildOperation();
    this->queryBuilder->buildValues(plant);
    this->proxyInventory->handle(this->queryBuilder->getQuery());
    
}
