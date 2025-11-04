/**
 * @file SelectQueryBuilder.cpp
 * @brief SelectQueryBuilder.cpp — Header and declarations for the SelectQueryBuilder.cpp component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#include "SelectQueryBuilder.h"
#include "QueryProduct.h"
#include <string>
#include <vector>

/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

void SelectQueryBuilder::selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType.empty() TODO - describe parameter
 */

    // if (!plantID.empty() && !maturityState.empty() && ! plantType.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param " TODO - describe parameter
 * @param " TODO - describe parameter
 * @param INVENTORY);" TODO - describe parameter
 */

    //     this->queryProduct->setQueryProduct("SELECT " + plantID + ", " + plantType + ", " + maturityState + " FROM INVENTORY);");
    // }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState.empty() TODO - describe parameter
 */

    // else if (!plantID.empty() && !plantType.empty() && maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param " TODO - describe parameter
 * @param INVENTORY);" TODO - describe parameter
 */

    //     this->queryProduct->setQueryProduct("SELECT " + plantID +  + ", " + plantType + " FROM INVENTORY);");
    // }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param !maturityState.empty() TODO - describe parameter
 */

    // else if (!plantID.empty() && plantType.empty() && !maturityState.empty()){


    //     this->queryProduct->setQueryProduct("SELECT " + plantID +  + ", " + maturityState + " FROM INVENTORY);");
    // }


    // else if (plantID.empty() && maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr The nullptr parameter used by the function.
 */

    //     this->queryProduct->setQueryProduct(nullptr);
    // }

    std::vector<std::string> queryFields;

    if (!plantID.empty()) queryFields.push_back(plantID);
    if (!plantType.empty()) queryFields.push_back(plantType);
    if (!maturityState.empty()) queryFields.push_back(maturityState);

    if (queryFields.empty()){
/**
 * @brief Execute the function's primary operation.
 * @param "" TODO - describe parameter
 */

        this->queryProduct->setQueryProduct("");
        return;
    }

    std::string finalQuery = "SELECT ";
    for (size_t i = 0; i < queryFields.size(); i++){
        finalQuery += queryFields[i];
        if (i + 1 < queryFields.size()) finalQuery += ", ";
    }
    finalQuery += " FROM INVENTORY;";


/**
 * @brief Execute the function's primary operation.
 * @param finalQuery The finalQuery parameter used by the function.
 */

    this->queryProduct->setQueryProduct(finalQuery);
}

/**
 * @brief Execute the function's primary operation.
 * @param selectPlant The selectPlant parameter used by the function.
 */

void SelectQueryBuilder::selectQueryBuilder(Plant* selectPlant){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param selectPlant->getPlantId() TODO - describe parameter
 */

    std::string plantID = std::to_string(selectPlant->getPlantId());
    std::string plantType = selectPlant->getName();
    std::string maturityState = selectPlant->getMaturityStateName();

    std::vector<std::string> queryFields;

    if (!plantID.empty()) queryFields.push_back(plantID);
    if (!plantType.empty()) queryFields.push_back(plantType);
    if (!maturityState.empty()) queryFields.push_back(maturityState);

    if (queryFields.empty()){


        this->queryProduct->setQueryProduct("");
        return;
    }

    std::string finalQuery = "SELECT ";
    for (size_t i = 0; i < queryFields.size(); i++){
        finalQuery += queryFields[i];
        if (i + 1 < queryFields.size()) finalQuery += ", ";
    }
    finalQuery += " FROM INVENTORY;";



    this->queryProduct->setQueryProduct(finalQuery);
    
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */

std::string SelectQueryBuilder::addPlantID(std::string plantID){
    if (plantID.length() == 0) return "";
    return plantID;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

std::string SelectQueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

std::string SelectQueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
}
