/**
 * @file DeleteQueryBuilder.cpp
 * @brief DeleteQueryBuilder.cpp — Header and declarations for the DeleteQueryBuilder.cpp component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#include "DeleteQueryBuilder.h"
#include "QueryProduct.h"
#include <vector>

/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

void DeleteQueryBuilder::deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param !maturityState.empty() 
 */

    // if (!plantID.empty() && !maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Maturity The Maturity parameter used by the function.
 */

    //     this->queryProduct->setQueryProduct("DELETE " + plantID + " FROM INVENTORY WHERE Maturity=" + maturityState);
    // }

    std::vector<std::string> queryFields;

    if (!plantID.empty()) queryFields.push_back("PlantID = '" + plantID + "'");
    if (!plantType.empty()) queryFields.push_back("PlantType = '" + plantType + "'");
    if (!maturityState.empty()) queryFields.push_back("MaturityState = '" + maturityState + "'");

    if (queryFields.empty()){
/**
 * @brief Execute the function's primary operation.
 * @param "" 
 */

        this->queryProduct->setQueryProduct("");
        return;
    }

    std::string finalQuery = "DELETE FROM INVENTORY WHERE ";
    for (size_t i = 0; i < queryFields.size(); ++i){
        finalQuery += queryFields[i];
        if (i + 1 < queryFields.size()) finalQuery += " AND ";
    }
    finalQuery += ";";

/**
 * @brief Execute the function's primary operation.
 * @param finalQuery The finalQuery parameter used by the function.
 */

    this->queryProduct->setQueryProduct(finalQuery);
}

/**
 * @brief Execute the function's primary operation.
 * @param deletePlant The deletePlant parameter used by the function.
 */

void DeleteQueryBuilder::deleteQueryBuilder(Plant* deletePlant){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deletePlant->getPlantId() 
 */

    std::string plantID = std::to_string(deletePlant->getPlantId());
    std::string plantType = deletePlant->getName();   
    std::string maturityState = deletePlant->getMaturityStateName();
    
    std::vector<std::string> queryFields;

    if (!plantID.empty()) queryFields.push_back("PlantID = '" + plantID + "'");
    if (!plantType.empty()) queryFields.push_back("PlantType = '" + plantType + "'");
    if (!maturityState.empty()) queryFields.push_back("MaturityState = '" + maturityState + "'");

    if (queryFields.empty()){


        this->queryProduct->setQueryProduct("");
        return;
    }

    std::string finalQuery = "DELETE FROM INVENTORY WHERE ";
    for (size_t i = 0; i < queryFields.size(); ++i){
        finalQuery += queryFields[i];
        if (i + 1 < queryFields.size()) finalQuery += " AND ";
    }
    finalQuery += ";";


    this->queryProduct->setQueryProduct(finalQuery);
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */

std::string DeleteQueryBuilder::addPlantID(std::string plantID){
    if (plantID.length() == 0) return "";
    return plantID;

}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

std::string DeleteQueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;

}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

std::string DeleteQueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
    
}
