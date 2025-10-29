#include "SelectQueryBuilder.h"
#include "QueryProduct.h"
#include <string>
#include <vector>

void SelectQueryBuilder::selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){
    // if (!plantID.empty() && !maturityState.empty() && ! plantType.empty()){
    //     this->queryProduct->setQueryProduct("SELECT " + plantID + ", " + plantType + ", " + maturityState + " FROM INVENTORY);");
    // }
    // else if (!plantID.empty() && !plantType.empty() && maturityState.empty()){
    //     this->queryProduct->setQueryProduct("SELECT " + plantID +  + ", " + plantType + " FROM INVENTORY);");
    // }
    // else if (!plantID.empty() && plantType.empty() && !maturityState.empty()){
    //     this->queryProduct->setQueryProduct("SELECT " + plantID +  + ", " + maturityState + " FROM INVENTORY);");
    // }
    // else if (plantID.empty() && maturityState.empty()){
    //     this->queryProduct->setQueryProduct(nullptr);
    // }

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

void SelectQueryBuilder::selectQueryBuilder(Plant* selectPlant){
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

std::string SelectQueryBuilder::addPlantID(std::string plantID){
    if (plantID.length() == 0) return "";
    return plantID;
}

std::string SelectQueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;
}

std::string SelectQueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
}
