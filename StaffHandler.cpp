#include "StaffHandler.h"

StaffHandler::StaffHandler(){
    this->successor = nullptr;
    this->staffSys = nullptr;
    this->queryBuilder = nullptr;
}

QueryProduct StaffHandler::createSelectQuery(std::string plantID, std::string plantType, std::string maturityState)
{
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);
    this->queryBuilder->selectQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct StaffHandler::createInsertQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);
    this->queryBuilder->insertQueryBuilder(plantID, plantType, maturityState);
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
