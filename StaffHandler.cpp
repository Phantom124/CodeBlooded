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

void StaffHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    }
    else if (staffSys == nullptr)
    {
        throw std::invalid_argument("StaffSystem is a nullptr.");
    }
    
    if (successor == nullptr){
        QueueIterator it = staffSys->createIterator();
        it.enqueue(command);
    } else {
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

QueryProduct *StaffHandler::createSelectQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);
    
    this->queryBuilder->selectQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct *StaffHandler::createSelectQuery(Plant* selectPlant){
    if (this->queryBuilder != nullptr) return nullptr;

    std::string plantID = std::to_string(selectPlant->getPlantId());
    std::string plantType = selectPlant->getName();
    std::string maturityState = selectPlant->getMaturityStateName();

    this->queryBuilder->selectQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct *StaffHandler::createInsertQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->insertQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct *StaffHandler::createInsertQuery(Plant* insertPlant){
    if (this->queryBuilder != nullptr) return nullptr;

    std::string plantID = std::to_string(insertPlant->getPlantId());
    std::string plantType = insertPlant->getName();
    std::string maturityState = insertPlant->getMaturityStateName();

    this->queryBuilder->insertQueryBuilder(plantID, plantType, maturityState);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct *StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->deleteQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

QueryProduct *StaffHandler::createDeleteQuery(Plant* deletePlant){
    if (this->queryBuilder != nullptr) return nullptr;

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