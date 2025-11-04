/**
 * @file StaffHandler.cpp
 * @brief Implementation of the StaffHandler base class used in the Chain of Responsibility.
 *
 * StaffHandler provides common behaviour for concrete handlers (WaterHandler, FertilizerHandler, etc.).
 * It coordinates request handling, forwarding to successors, and building query products using a QueryBuilder.
 *
 * Author: Jared Williams
 * @date 2025-11-04
 */

#include "StaffHandler.h"
#include "StaffSystem.h"
#include "QueryBuilder.h"
#include "Plant.h"
#include <iostream>
#include <stdexcept>

StaffHandler::StaffHandler()
{
    successor = nullptr;
    queryBuilder = nullptr;
    isAvailable = true;
}

StaffHandler::~StaffHandler() = default;

/**
 * @brief Handle a command: validate, attempt to process or forward/enqueue it.
 * @param command Pointer to the Command to handle (must not be null).
 * @param staffSys Pointer to the StaffSystem providing queue/context for handlers.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *command TODO - describe parameter
 * @param staffSys The staffSys parameter used by the function.
 */
void StaffHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        // Validate inputs
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr." TODO - describe parameter
 */
        throw std::invalid_argument("Command is a nullptr.");
    }
    else if (staffSys == nullptr)
    {
        // Validate inputs

        throw std::invalid_argument("StaffSystem is a nullptr.");
    }

    if (successor == nullptr){
        // No successor: enqueue the command into the staff system's queue for later processing
        QueueIterator it = staffSys->createIterator();
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 */
        it.enqueue(command);
    } else {
        // Forward the request to the next handler in the chain
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */
        successor->handleRequest(command, staffSys);
    }
}

void StaffHandler::setSuccessor(StaffHandler *successor)
{
    if (this->successor == nullptr)
    {
        this->successor = successor;
    }
    else
    {
        // delete this->successor;
        this->successor = successor;
    }
}

StaffHandler *StaffHandler::getSuccessor(){
    return successor;
}

/**
 * @brief Build a SELECT query product using the QueryBuilder configured on this handler.
 * @param plantID Plant identifier to filter by (empty string allowed).
 * @param plantType Plant type/name to filter by (empty string allowed).
 * @param maturityState Maturity/growth state to filter by (empty string allowed).
 * @return QueryProduct* A built QueryProduct ready for execution, or nullptr if no QueryBuilder is set.
 */
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */
QueryProduct *StaffHandler::createSelectQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    // Add components to the builder and construct the final select query
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 */
    std::string id = queryBuilder->addPlantID(plantID);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */
    std::string type = this->queryBuilder->addPlantType(plantType);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param maturityState The maturityState parameter used by the function.
 */
    std::string state = this->queryBuilder->addMaturityState(maturityState);

/**
 * @brief Execute the function's primary operation.
 * @param id The id parameter used by the function.
 * @param type The type parameter used by the function.
 * @param state The state parameter used by the function.
 */
    this->queryBuilder->selectQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Build a SELECT query for a specific Plant instance.
 * @param selectPlant Pointer to the plant to select by (uses its id, type and maturity).
 * @return QueryProduct* Built QueryProduct or nullptr if QueryBuilder is not configured.
 */
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param selectPlant The selectPlant parameter used by the function.
 */
QueryProduct *StaffHandler::createSelectQuery(Plant* selectPlant){
    if (this->queryBuilder == nullptr) return nullptr;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param selectPlant->getPlantId() TODO - describe parameter
 */
    std::string plantID = std::to_string(selectPlant->getPlantId());
    std::string plantType = selectPlant->getName();
    std::string maturityState = selectPlant->getMaturityStateName();

/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */
    this->queryBuilder->selectQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Build an INSERT query product using the QueryBuilder.
 * @param plantID Plant identifier to insert (string form).
 * @param plantType Plant type/name to insert.
 * @param maturityState Maturity/growth state to insert.
 * @return QueryProduct* Built QueryProduct or nullptr if QueryBuilder is not configured.
 */

QueryProduct *StaffHandler::createInsertQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);

    std::string type = this->queryBuilder->addPlantType(plantType);

    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->insertQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Build an INSERT query for a provided Plant instance.
 * @param insertPlant Pointer to the Plant to insert (uses its id, type, maturity state).
 * @return QueryProduct* Built QueryProduct or nullptr if QueryBuilder is not configured.
 */
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param insertPlant The insertPlant parameter used by the function.
 */
QueryProduct *StaffHandler::createInsertQuery(Plant* insertPlant){
    if (this->queryBuilder == nullptr) return nullptr;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param insertPlant->getPlantId() TODO - describe parameter
 */
    std::string plantID = std::to_string(insertPlant->getPlantId());
    std::string plantType = insertPlant->getName();
    std::string maturityState = insertPlant->getMaturityStateName();

    this->queryBuilder->insertQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Build a DELETE query product using the QueryBuilder.
 * @param plantID Plant identifier to delete (string form).
 * @param plantType Plant type/name to delete.
 * @param maturityState Maturity/growth state to delete.
 * @return QueryProduct* Built QueryProduct or nullptr if QueryBuilder is not configured.
 */

QueryProduct *StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);

    std::string type = this->queryBuilder->addPlantType(plantType);

    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->deleteQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

/**
 * @brief Build a DELETE query for a provided Plant instance.
 * @param deletePlant Pointer to the Plant to delete (uses its id, type, maturity state).
 * @return QueryProduct* Built QueryProduct or nullptr if QueryBuilder is not configured.
 */
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deletePlant The deletePlant parameter used by the function.
 */
QueryProduct *StaffHandler::createDeleteQuery(Plant* deletePlant){
    if (this->queryBuilder == nullptr) return nullptr;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deletePlant->getPlantId() TODO - describe parameter
 */
    std::string plantID = std::to_string(deletePlant->getPlantId());
    std::string plantType = deletePlant->getName();
    std::string maturityState = deletePlant->getMaturityStateName();

    this->queryBuilder->deleteQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

void StaffHandler::resetAvailable()
{
    isAvailable = true;
    if (successor != nullptr)
    {
        successor->resetAvailable();
    }
}

void StaffHandler::setQueryBuilder(QueryBuilder *qb)
{
    if (queryBuilder == nullptr)
    {
        queryBuilder = qb;
        return;
    }

    // delete queryBuilder;
    // queryBuilder = qb;
}   
