#include "Customer.h"

QueryProduct Customer::createSelectQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);
    this->queryBuilder->selectQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

void Customer::setQueryBuilder(QueryBuilder* queryBuilder){
    this->queryBuilder = queryBuilder;
}
