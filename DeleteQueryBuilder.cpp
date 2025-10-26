#include "DeleteQueryBuilder.h"
#include <vector>

void DeleteQueryBuilder::deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){
    // if (!plantID.empty() && !maturityState.empty()){
    //     this->queryProduct->setQueryProduct("DELETE " + plantID + " FROM INVENTORY WHERE Maturity=" + maturityState);
    // }

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