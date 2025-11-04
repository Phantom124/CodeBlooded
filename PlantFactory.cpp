#include "PlantFactory.h"
#include "InsertQueryBuilder.h"  
#include <stdexcept>

PlantFactory::PlantFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon, QueryBuilder* queryBuilder){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
        throw std::invalid_argument("Monitors cannot be null");
    }
    this->waterMonitor = waterMon;
    this->fertilizerMonitor = fertMon;
    this->deadMonitor = deadMon;
    if (queryBuilder != nullptr){
        this->queryBuilder = queryBuilder;
        this->ownsQueryBuilder = false;
    } else {
        this->queryBuilder = new InsertQueryBuilder(); 
        this->ownsQueryBuilder = true;
    }
}

PlantFactory::~PlantFactory(){
    if (ownsQueryBuilder && queryBuilder != nullptr){
        delete queryBuilder;  
    }
    queryBuilder = nullptr;
}