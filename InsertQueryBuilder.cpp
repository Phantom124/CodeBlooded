#include "InsertQueryBuilder.h"
#include <vector>

void InsertQueryBuilder::insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){
    // if (!plantID.empty() && !maturityState.empty()){
    //     this->queryProduct->setQueryProduct("INSERT INTO INVENTORY VALUES(" + plantID + ", " + maturityState + ");");
    // }
    // else if (!plantID.empty() && maturityState.empty()){
    //     this->queryProduct->setQueryProduct("INSERT INTO INVENTORY VALUES(" + plantID + ");");

    // }

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

    // std::string finalQuery = "INSERT INTO INVENTORY VALUES (";
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


    this->queryProduct->setQueryProduct(finalQuery);

}