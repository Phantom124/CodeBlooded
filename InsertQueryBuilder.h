#ifndef INSERTQUERYBUILDER_H
#define INSERTQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class InsertQueryBuilder : public QueryBuilder {
public:
    InsertQueryBuilder();
    ~InsertQueryBuilder();

    void buildOriginator(std::string org);
    void buildOperation();
    void buildValues(Plant* p);
    // void buildAndSendQuery();
};


#endif