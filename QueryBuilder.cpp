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

void QueryBuilder::selectQueryBuilder(Plant* plant) {
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "SELECT " << plant->getPlantId()
       << " FROM PLANTS WHERE Type='" << plant->getName()
       << "' AND MaturityState='" << plant->getMaturityStateName() << "';";

    this->queryProduct->setQueryProduct(ss.str());
}

void QueryBuilder::insertQueryBuilder(Plant *plant){
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "INSERT INTO PLANTS VALUES('"
       << plant->getPlantId() << "', '"
       << plant->getName() << "', '"
       << plant->getMaturityStateName() << "');";

    this->queryProduct->setQueryProduct(ss.str());
}

void QueryBuilder::deleteQueryBuilder(Plant* plant) {
    if (plant == nullptr) return;

    std::stringstream ss;
    ss << "DELETE FROM PLANTS WHERE PlantID='"
       << plant->getPlantId() << "';";

    this->queryProduct->setQueryProduct(ss.str());
}

std::string QueryBuilder::addPlantID(std::string plantID)
{
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