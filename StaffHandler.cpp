#include "StaffHandler.h"
// #include "QueryBuilder.h"
// #include "DeleteQueryBuilder.h"

StaffHandler::StaffHandler(StaffSystem* sys){
    staffSys = sys;
    successor = NULL;
    queryBuilder = NULL;
}

void StaffHandler::setSuccessor(StaffHandler *successor){
    if (this->successor == NULL){
        this->successor = successor;
    }
}

QueryProduct* StaffHandler::createDeleteQuery(string plantID, string plantType, string maturityState){
    if (queryBuilder == NULL){
        return NULL;
        //Not sure whether I should return NULL here or if I should just create a QBuilder
    }
    
    // deleteBuilder->deleteQueryBuilder(plantID, plantType, maturityState);
    // queryBuilder->
}

void StaffHandler::setQueryBuilder(QueryBuilder *qb)
{
    if (queryBuilder == NULL){
        queryBuilder = qb;
        return;
    }

    delete queryBuilder;
    queryBuilder = qb;
}
