#include "StaffHandler.h"
#include "StaffSystem.h"

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
    
    if (successor == false){
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
        delete this->successor;
        this->successor = successor;
    }
}

void StaffHandler::resetBusy(){
    isBusy = false;
    if (successor != nullptr){
        successor->resetBusy();
    }
}

void StaffHandler::setQueryBuilder(QueryBuilder *qb){
    if (queryBuilder == nullptr){
        queryBuilder = qb;
        return;
    }

    delete queryBuilder;
    queryBuilder = qb;
}