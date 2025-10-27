#include "StaffHandler.h"
#include "StaffSystem.h"
// #include "QueryBuilder.h"
// #include "DeleteQueryBuilder.h"

StaffHandler::StaffHandler(){
    successor = nullptr;
    queryBuilder = nullptr;
}

void StaffHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw "Command is nullptr.";
    } else if (staffSys == nullptr){
        throw "StaffSys is nullptr";
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
    }
}

QueryProduct* StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    if (queryBuilder == nullptr){
        return nullptr;
        //Not sure whether I should return nullptr here or if I should just create a QBuilder
    }
    
    // deleteBuilder->deleteQueryBuilder(plantID, plantType, maturityState);
    // queryBuilder->
}

void StaffHandler::setQueryBuilder(QueryBuilder *qb){
    if (queryBuilder == nullptr){
        queryBuilder = qb;
        return;
    }

    delete queryBuilder;
    queryBuilder = qb;
}