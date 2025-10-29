#include "Customer.h"
#include "QueryProduct.h"

QueryProduct Customer::createSelectQuery(std::string plantID, std::string plantType, std::string maturityState){
    if (this->queryBuilder == nullptr) return QueryProduct(nullptr);

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->selectQueryBuilder(id, type, state);
    return *(this->queryBuilder->getQueryProduct());
}

void Customer::setQueryBuilder(QueryBuilder* queryBuilder){
    this->queryBuilder = queryBuilder;
}
