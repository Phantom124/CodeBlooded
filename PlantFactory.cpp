/**
 * @file PlantFactory.cpp
 * @brief PlantFactory.cpp — Header and declarations for the PlantFactory.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "PlantFactory.h"
#include "InsertQueryBuilder.h"  
#include <stdexcept>

/**
 * @brief Execute the function's primary operation.
 * @param *waterMon 
 * @param *fertMon 
 * @param *deadMon 
 * @param queryBuilder The queryBuilder parameter used by the function.
 */

PlantFactory::PlantFactory(WaterMonitor *waterMon, FertilizerMonitor *fertMon, DeadMonitor *deadMon, QueryBuilder* queryBuilder){
    if( waterMon == nullptr || fertMon == nullptr || deadMon == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param null
 */

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
