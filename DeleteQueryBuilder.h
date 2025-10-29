#ifndef DELETEQUERYBUILDER_H
#define DELETEQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class DeleteQueryBuilder: public QueryBuilder{
    public:
        void deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
        void deleteQueryBuilder(Plant* deletePlant);

        std::string addPlantID(std::string plantID);
        std::string addPlantType(std::string plantType);
        std::string addMaturityState(std::string maturityState);

    private:
        Plant* deletePlant;
};

#endif