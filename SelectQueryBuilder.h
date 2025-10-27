#ifndef SELECTQUERYBUILDER_H
#define SELECTQUERYBUILDER_H

#include "QueryBuilder.h"

class SelectQueryBuilder: public QueryBuilder{
    public:
        void selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
        std::string addPlantID(std::string plantID);
        std::string addPlantType(std::string plantType);
        std::string addMaturityState(std::string maturityState);

};

#endif