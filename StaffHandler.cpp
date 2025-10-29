#include "StaffHandler.h"
#include "StaffSystem.h"
#include <iostream>
#include <stdexcept>

StaffHandler::StaffHandler(){
    successor = nullptr;
    queryBuilder = nullptr;
}

void StaffHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr.");
    }
    
    if (successor == nullptr){
        std::cout<<"No successor found, enqueuing command directly."<<std::endl;
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

QueryProduct *StaffHandler::createSelectQuery(string plantID, string plantType, string maturityState){
    std::cout<<"Creating Select Query"<<std::endl;
    return nullptr;
}

QueryProduct *StaffHandler::createInsertQuery(string plantID, string plantType, string maturityState){
    std::cout<<"Creating Insert Query"<<std::endl;
    return nullptr;
}

QueryProduct *StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    std::cout<<"Creating Delete Query"<<std::endl;
    return nullptr;
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