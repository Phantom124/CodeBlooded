/**
 * @file QueryBuilder.h
 * @brief QueryBuilder.h — Header and declarations for the QueryBuilder.h component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

// #include "PlantGrowthState.h"
#include "Plant.h"
// #include "QueryProduct.h"
#include <string>

class QueryProduct;
class Plant;

class QueryProduct;

class QueryBuilder{
    public:
        QueryBuilder();
        virtual ~QueryBuilder();

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

        virtual void selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);


        virtual void insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);


        virtual void deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */

        virtual void selectQueryBuilder(Plant* plant);


        virtual void insertQueryBuilder(Plant* plant);


        virtual void deleteQueryBuilder(Plant* plant);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */

        virtual std::string addPlantID(std::string plantID);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

        virtual std::string addPlantType(std::string plantType);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

        virtual std::string addMaturityState(std::string maturityState);

        
        QueryProduct* getQueryProduct();
        

    protected:
        QueryProduct* queryProduct;
};

#endif
