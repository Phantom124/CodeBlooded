#ifndef INSERTQUERYBUILDER_H
#define INSERTQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class InsertQueryBuilder: public QueryBuilder{
public:
    InsertQueryBuilder();
    ~InsertQueryBuilder();

    void insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
    void insertQueryBuilder(Plant* insertPlant);

    std::string addPlantID(std::string plantID);
    std::string addPlantType(std::string plantType);
    std::string addMaturityState(std::string maturityState);

private:
    Plant* insertPlant = nullptr; // non-owning by default; use unique_ptr if ownership needed
};

#endif