#ifndef INSERTQUERYBUILDER_H
#define INSERTQUERYBUILDER_H

#include "QueryBuilder.h"

class InsertQueryBuilder: public QueryBuilder{
    public:
        void insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);

};

#endif