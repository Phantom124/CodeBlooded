/**
 * @file Customer.h
 * @brief Customer.h — Header and declarations for the Customer.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "QueryBuilder.h"
#include "SelectQueryBuilder.h"
#include "Plant.h"

class Customer {
    public:
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

        QueryProduct createSelectQuery(std::string plantID, std::string plantType, std::string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */

        QueryProduct* createSelectQuery(Plant* plant);
/**
 * @brief Execute the function's primary operation.
 * @param queryBuilder The queryBuilder parameter used by the function.
 */

        void setQueryBuilder(QueryBuilder* queryBuilder);

    private:
        QueryBuilder* queryBuilder;
};

#endif
