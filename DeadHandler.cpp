#include "DeadHandler.h"
#include "DeadCommand.h" 

DeadHandler::DeadHandler(){}

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command->getType() == DEAD){
        
        //Remove the dead plant from the queue
        DeadCommand* deadCmd = dynamic_cast<DeadCommand*>(command);
        Plant* plant = deadCmd->getPlant();
        createDeleteQuery(plant->getId(), plant->getName(), plant->getMaturityState());
        // TODO: Figure out how the DeleteQuery works

    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}