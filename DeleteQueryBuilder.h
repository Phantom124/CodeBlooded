#ifndef DELETEQUERYBUILDER_H
#define DELETEQUERYBUILDER_H

#include "QueryBuilder.h"

class DeleteQueryBuilder: public QueryBuilder{
    public:
        void deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);

        std::string addPlantID();
        std::string addPlantType();
        std::string addMaturityState();

    private:
        std::string plantID;
        std::string plantType;
        std::string maturityState;
};

#endif