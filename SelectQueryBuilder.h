/**
 * @file SelectQueryBuilder.h
 * @brief SelectQueryBuilder.h — Header and declarations for the SelectQueryBuilder.h component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef SELECTQUERYBUILDER_H
#define SELECTQUERYBUILDER_H

#include "QueryBuilder.h"
// #include "Plant.h"
class Plant;

class SelectQueryBuilder: public QueryBuilder{
    public:
/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

        void selectQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @param selectPlant The selectPlant parameter used by the function.
 */

        void selectQueryBuilder(Plant* selectPlant);
        
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */

        std::string addPlantID(std::string plantID);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

        std::string addPlantType(std::string plantType);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */

        std::string addMaturityState(std::string maturityState);

    private:
        Plant* selectPlant;
};

#endif
