#include "QueryBuilder.h"

QueryBuilder::QueryBuilder(){
    this->queryProduct = new QueryProduct(nullptr);
}

QueryBuilder::~QueryBuilder(){
    delete this->queryProduct;
    this->queryProduct = nullptr;
}

void QueryBuilder::selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}
void QueryBuilder::insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}
void QueryBuilder::deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState){}

QueryProduct QueryBuilder::getQueryProduct()
{
    return *this->queryProduct;
}