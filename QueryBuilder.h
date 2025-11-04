#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

// #include "PlantGrowthState.h"
#include "Plant.h"
// #include "QueryProduct.h"
#include <string>

// class QueryProduct;
class Plant;
class GreenHouseInventory;

class Query;

class QueryBuilder {
protected:
    Query* query;
    GreenHouseInventory* inventory;  // reference to where it will be executed
public:
    QueryBuilder();
    virtual ~QueryBuilder();

    virtual void createNewQuery();
    Query* getQuery();

    virtual void buildOriginator(std::string originator) = 0;
    virtual void buildOperation() = 0;
    virtual void buildValues(Plant* p) = 0;
    virtual void buildAndSendQuery() = 0;
};

#endif