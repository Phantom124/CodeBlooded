#ifndef DELETEQUERYBUILDER_H
#define DELETEQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class DeleteQueryBuilder : public QueryBuilder {
public:
    DeleteQueryBuilder();

    void buildOriginator(const std::string& org);
    void buildOperation();
    void buildValues(Plant* p);
    // void buildAndSendQuery();
};


#endif