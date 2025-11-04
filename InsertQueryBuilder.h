/**
 * @file InsertQueryBuilder.h
 * @brief InsertQueryBuilder.h — Header and declarations for the InsertQueryBuilder.h component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef INSERTQUERYBUILDER_H
#define INSERTQUERYBUILDER_H

#include "QueryBuilder.h"
#include "Plant.h"

class InsertQueryBuilder: public QueryBuilder{
public:
    InsertQueryBuilder();
    ~InsertQueryBuilder();

/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

    void insertQueryBuilder(std::string plantID, std::string plantType, std::string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @param insertPlant The insertPlant parameter used by the function.
 */

    void insertQueryBuilder(Plant* insertPlant);

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
    Plant* insertPlant = nullptr; // non-owning by default; use unique_ptr if ownership needed
};

#endif
