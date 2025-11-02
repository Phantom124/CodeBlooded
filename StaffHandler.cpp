#include "StaffHandler.h"
#include "StaffSystem.h"
#include "QueryBuilder.h"
#include <iostream>
#include <stdexcept>

StaffHandler::StaffHandler(){
    successor = nullptr;
    queryBuilder = nullptr;
    isAvailable = true;
}

// StaffHandler::~StaffHandler(){
// }

void StaffHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr.");
    }
    
    if (successor == nullptr){
        QueueIterator it = staffSys->createIterator();
        it.enqueue(command);
    } else {
        successor->handleRequest(command, staffSys);
    }
}

void StaffHandler::setSuccessor(StaffHandler *successor){
    if (this->successor == nullptr){
        this->successor = successor;
    } else {
        // delete this->successor;
        this->successor = successor;
    }
}

StaffHandler *StaffHandler::getSuccessor(){
    return successor;
}

QueryProduct *StaffHandler::createSelectQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);
    
    this->queryBuilder->selectQueryBuilder(id, type, state);
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

QueryProduct *StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    if (this->queryBuilder == nullptr) return nullptr;

    std::string id = this->queryBuilder->addPlantID(plantID);
    std::string type = this->queryBuilder->addPlantType(plantType);
    std::string state = this->queryBuilder->addMaturityState(maturityState);

    this->queryBuilder->deleteQueryBuilder(id, type, state);
    return this->queryBuilder->getQueryProduct();
}

void StaffHandler::resetAvailable()
{
    isAvailable = true;
    if (successor != nullptr){
        successor->resetAvailable();
    }
}

void StaffHandler::setQueryBuilder(QueryBuilder *qb){
    if (queryBuilder == nullptr){
        queryBuilder = qb;
        return;
    }

    // delete queryBuilder;
    // queryBuilder = qb;
}   