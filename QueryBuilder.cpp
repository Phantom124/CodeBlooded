#include "QueryBuilder.h"
#include "QueryProduct.h"

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

std::string QueryBuilder::addPlantID(std::string plantID){
    if (plantID.length() == 0) return "";
    return plantID;
}

std::string QueryBuilder::addPlantType(std::string plantType){
    if (plantType.length() == 0) return "";
    return plantType;
}

std::string QueryBuilder::addMaturityState(std::string maturityState){
    if (maturityState.length() == 0) return "";
    return maturityState;
}

QueryProduct* QueryBuilder::getQueryProduct(){
    return this->queryProduct;
}