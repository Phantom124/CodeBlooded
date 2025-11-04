#ifndef SELECTQUERYBUILDER_H
#define SELECTQUERYBUILDER_H

#include "QueryBuilder.h"
// #include "Plant.h"
class Plant;

class SelectQueryBuilder : public QueryBuilder {
public:
    SelectQueryBuilder();

    void buildOriginator(std::string org);
    void buildOperation();
    void buildValues(Plant* p);
    // virtual void buildAndSendQuery();
};

#endif