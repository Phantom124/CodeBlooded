/**
 * @file Customer.cpp
 * @brief Customer.cpp — Header and declarations for the Customer.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Customer.h"
#include "QueryProduct.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */
QueryProduct Customer::createSelectQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);


/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */
    std::string id = this->queryBuilder->addPlantID(plantID);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */
    std::string type = this->queryBuilder->addPlantType(plantType);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */
    std::string state = this->queryBuilder->addMaturityState(maturityState);

/**
 * @brief Execute the function's primary operation.
 * @param id The id parameter used by the function.
 * @param type The type parameter used by the function.
 * @param state The state parameter used by the function.
 */
    this->queryBuilder->selectQueryBuilder(id, type, state);
    return *(this->queryBuilder->getQueryProduct());
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */
QueryProduct *Customer::createSelectQuery(Plant* plant){

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant->getPlantId() TODO - describe parameter
 */
    std::string plantID = std::to_string(plant->getPlantId());
    std::string plantType = plant->getName();
    std::string maturityState = plant->getMaturityStateName();


/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */
    this->queryBuilder->selectQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Execute the function's primary operation.
 * @param queryBuilder The queryBuilder parameter used by the function.
 */
void Customer::setQueryBuilder(QueryBuilder* queryBuilder){
    this->queryBuilder = queryBuilder;
}
