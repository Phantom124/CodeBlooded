#ifndef SELECTQUERYBUILDER_H
#define SELECTQUERYBUILDER_H

#include "QueryBuilder.h"
// #include "Plant.h"
class Plant;

class SelectQueryBuilder: public QueryBuilder{
    public:
        void selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
        void selectQueryBuilder(Plant* selectPlant);
        
        std::string addPlantID(std::string plantID);
        std::string addPlantType(std::string plantType);
        std::string addMaturityState(std::string maturityState);

    private:
        Plant* selectPlant;
};

#endif