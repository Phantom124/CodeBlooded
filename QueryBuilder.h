#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

// #include "PlantGrowthState.h"
#include "Plant.h"
// #include "QueryProduct.h"
#include <string>

class QueryProduct;
class Plant;

class QueryProduct;

class QueryBuilder{
    public:
        QueryBuilder();
        virtual ~QueryBuilder();

        virtual void selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
        virtual void insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
        virtual void deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);

        virtual std::string addPlantID(std::string plantID);
        virtual std::string addPlantType(std::string plantType);
        virtual std::string addMaturityState(std::string maturityState);

        
        QueryProduct* getQueryProduct();
        

    protected:
        QueryProduct* queryProduct;
};

#endif