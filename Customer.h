#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "QueryBuilder.h"
#include "SelectQueryBuilder.h"
#include "Plant.h"
#include "GreenHouseInventory.h"
#include "QueryProduct.h"

class Customer {
    public:
        Customer(GreenHouseInventory* inventory, QueryBuilder* queryBuilder)
            : inventory(inventory), queryBuilder(queryBuilder) {};
        // QueryProduct createSelectQuery(std::string plantID, std::string plantType, std::string maturityState);
        // QueryProduct* createSelectQuery(Plant* plant);
        // void setQueryBuilder(QueryBuilder* queryBuilder);
        void createSelectQuery();

    private:
        QueryBuilder* queryBuilder;
        GreenHouseInventory* inventory; 
};

#endif