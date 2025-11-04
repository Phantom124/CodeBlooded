/**
 * @file QueryBuilder.cpp
 * @brief QueryBuilder.cpp — Header and declarations for the QueryBuilder.cpp component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#include "QueryBuilder.h"
#include "QueryProduct.h"
#include "SharedInstances.h"

QueryBuilder::QueryBuilder(){
    if (g_sharedInventory != nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param g_sharedInventory The g_sharedInventory parameter used by the function.
 */

        this->queryProduct = new QueryProduct(g_sharedInventory);
        return;
    }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr The nullptr parameter used by the function.
 */

    this->queryProduct = new QueryProduct(nullptr);
}

QueryBuilder::~QueryBuilder(){
    delete this->queryProduct;
    this->queryProduct = nullptr;
}

/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

void QueryBuilder::selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}


void QueryBuilder::insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}


void QueryBuilder::deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}

/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

void QueryBuilder::selectQueryBuilder(Plant* plant) {
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "SELECT " << plant->getPlantId()
       << " FROM PLANTS WHERE Type='" << plant->getName()
       << "' AND MaturityState='" << plant->getMaturityStateName() << "';";

/**
 * @brief Execute the function's primary operation.
 * @param ss.str() TODO - describe parameter
 */

    this->queryProduct->setQueryProduct(ss.str());
}

/**
 * @brief Execute the function's primary operation.
 * @param *plant TODO - describe parameter
 */

void QueryBuilder::insertQueryBuilder(Plant *plant){
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "INSERT INTO PLANTS VALUES('"
       << plant->getPlantId() << "', '"
       << plant->getName() << "', '"
       << plant->getMaturityStateName() << "');";


    this->queryProduct->setQueryProduct(ss.str());
}


void QueryBuilder::deleteQueryBuilder(Plant* plant) {
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "DELETE FROM PLANTS WHERE PlantID='"
       << plant->getPlantId() << "';";


    this->queryProduct->setQueryProduct(ss.str());
}

std::string QueryBuilder::addPlantID(std::string plantID)
{
    if (plantID.length() == 0) return "";
    return plantID;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

std::string QueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

std::string QueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
}

QueryProduct* QueryBuilder::getQueryProduct(){
    return this->queryProduct;
}
