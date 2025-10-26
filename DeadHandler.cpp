#include "DeadHandler.h"
#include "DeadCommand.h" 

DeadHandler::DeadHandler(StaffSystem *sys) 
    : StaffHandler(sys){}

void DeadHandler::handleRequest(Command *command){
    if (command->getType() == DEAD){
        
        //Remove the dead plant from the queue
        DeadCommand* deadCmd = dynamic_cast<DeadCommand*>(command);
        Plant* plant = deadCmd->getPlant();
        createDeleteQuery(plant->getId(), plant->getName(), plant->getMaturityState());

    } else {
        StaffHandler::handleRequest(command);
    }
}