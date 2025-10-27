#include "StaffHandler.h"
#include "QueryBuilder.h"
#include "QueryProduct.h"

StaffHandler::StaffHandler(){
    this->successor = nullptr;
    this->staffSys = nullptr;
    this->queryBuilder = nullptr;
}

QueryProduct StaffHandler::createSelectQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->selectQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct StaffHandler::createInsertQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->insertQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct StaffHandler::createDeleteQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);
    this->queryBuilder->deleteQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

void StaffHandler::setQueryBuilder(QueryBuilder* queryBuilder){
    this->queryBuilder = queryBuilder;
}
