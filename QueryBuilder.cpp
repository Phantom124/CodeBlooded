#include "QueryBuilder.h"
#include "QueryProduct.h"
// #include "SharedInstances.h"
#include "GreenHouseInventory.h"

QueryBuilder::QueryBuilder(){
    this->query = nullptr;
}

QueryBuilder::~QueryBuilder(){
    if (this->query != nullptr) {
        delete this->query;
        this->query = nullptr;
    }
}

void QueryBuilder::createNewQuery(){
    if (this->query != nullptr) {
        delete this->query;
    }
    this->query = new Query();
}

Query *QueryBuilder::getQuery(){
    return this->query;
}
