/**
 * @file InsertQueryBuilder.cpp
 * @brief InsertQueryBuilder.cpp — Header and declarations for the InsertQueryBuilder.cpp component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#include "InsertQueryBuilder.h"
#include "QueryProduct.h"
#include <vector>

void InsertQueryBuilder::insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState)
{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param !maturityState.empty() 
 */

    // if (!plantID.empty() && !maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    //     this->queryProduct->setQueryProduct("INSERT INTO INVENTORY VALUES(" + plantID + ", " + maturityState + ");");
    // }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState.empty() 
 */

    // else if (!plantID.empty() && maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    //     this->queryProduct->setQueryProduct("INSERT INTO INVENTORY VALUES(" + plantID + ");");

    // }

    std::vector<std::string> queryCol;
    std::vector<std::string> queryValue;

    if (!plantID.empty()){ 
/**
 * @brief Execute the function's primary operation.
 * @param "PlantID" 
 */

        queryCol.push_back("PlantID");
/**
 * @brief Execute the function's primary operation.
 * @param "'"
 */

        queryValue.push_back("'" + plantID + "'");
    }

    if (!plantType.empty()){
/**
 * @brief Execute the function's primary operation.
 * @param "PlantType" 
 */

        queryCol.push_back("PlantType");


        queryValue.push_back("'" + plantType + "'");
    }

    if (!maturityState.empty()){
/**
 * @brief Execute the function's primary operation.
 * @param "MaturityState" 
 */

        queryCol.push_back("MaturityState");


        queryValue.push_back("'" + maturityState + "'");
    }



    if (queryCol.empty()){
/**
 * @brief Execute the function's primary operation.
 * @param ""
 */

        this->queryProduct->setQueryProduct("");
        return;
    }

    // std::string finalQuery = "INSERT INTO INVENTORY VALUES (";
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    // for (size_t i = 0; i < queryFields.size(); i++){
    //     finalQuery += queryFields[i];
    //     if (i + 1 < queryFields.size()) finalQuery += ", ";
    // }
    // finalQuery += ");";

    std::string finalQuery = "INSERT INTO INVENTORY (";
    for (size_t i = 0; i < queryCol.size(); i++){
        finalQuery += queryCol[i];
        if (i + 1 < queryCol.size()) finalQuery += ", ";
    }

    finalQuery += ") VALUES (";

    for (size_t i = 0; i < queryValue.size(); i++){
        finalQuery += queryValue[i];
        if (i + 1 < queryValue.size()) finalQuery += ", ";
    }

    finalQuery += ");";


/**
 * @brief Execute the function's primary operation.
 * @param finalQuery The finalQuery parameter used by the function.
 */

    this->queryProduct->setQueryProduct(finalQuery);
}

InsertQueryBuilder::InsertQueryBuilder(){
    this->insertPlant = nullptr;
}

InsertQueryBuilder::~InsertQueryBuilder(){
    delete this->insertPlant;
    this->insertPlant = nullptr;
}

void InsertQueryBuilder::insertQueryBuilder(Plant *insertPlant)
{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param insertPlant->getPlantId() 
 */

    std::string plantID = std::to_string(insertPlant->getPlantId());
    std::string plantType = insertPlant->getName();
    std::string maturityState = insertPlant->getMaturityStateName();

    std::vector<std::string> queryCol;
    std::vector<std::string> queryValue;

    if (!plantID.empty()){ 


        queryCol.push_back("PlantID");


        queryValue.push_back("'" + plantID + "'");
    }

    if (!plantType.empty()){


        queryCol.push_back("PlantType");


        queryValue.push_back("'" + plantType + "'");
    }

    if (!maturityState.empty()){


        queryCol.push_back("MaturityState");


        queryValue.push_back("'" + maturityState + "'");
    }



    if (queryCol.empty()){


        this->queryProduct->setQueryProduct("");
        return;
    }

    std::string finalQuery = "INSERT INTO INVENTORY (";
    for (size_t i = 0; i < queryCol.size(); i++){
        finalQuery += queryCol[i];
        if (i + 1 < queryCol.size()) finalQuery += ", ";
    }

    finalQuery += ") VALUES (";

    for (size_t i = 0; i < queryValue.size(); i++){
        finalQuery += queryValue[i];
        if (i + 1 < queryValue.size()) finalQuery += ", ";
    }

    finalQuery += ");";



    this->queryProduct->setQueryProduct(finalQuery);
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */

std::string InsertQueryBuilder::addPlantID(std::string plantID){
    if (plantID.length() == 0) return "";
    return plantID;

}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

std::string InsertQueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;

}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

std::string InsertQueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
    
}
