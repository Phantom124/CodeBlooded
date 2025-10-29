#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "QueryBuilder.h"
#include "SelectQueryBuilder.h"

class Customer {
    public:
        QueryProduct createSelectQuery(std::string plantID, std::string plantType, std::string maturityState);
        void setQueryBuilder(QueryBuilder* queryBuilder);

    private:
        QueryBuilder* queryBuilder = nullptr;
};

#endif
