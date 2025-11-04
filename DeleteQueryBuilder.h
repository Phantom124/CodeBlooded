/**
 * @file DeleteQueryBuilder.h
 * @brief DeleteQueryBuilder.h — Header and declarations for the DeleteQueryBuilder.h component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef DELETEQUERYBUILDER_H
#define DELETEQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class DeleteQueryBuilder: public QueryBuilder{
    public:
/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

        void deleteQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @param deletePlant The deletePlant parameter used by the function.
 */

        void deleteQueryBuilder(Plant* deletePlant);

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
        Plant* deletePlant;
};

#endif
