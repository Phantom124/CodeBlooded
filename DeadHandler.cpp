#include "DeadHandler.h"
#include "DeadCommand.h" 

DeadHandler::DeadHandler(){}

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw "Command is nullptr.";
    } else if (staffSys == nullptr){
        throw "StaffSys is nullptr";
    }

    if (command->getType() == DEAD){
        isBusy = false;
        //Remove the dead plant from the queue
        DeadCommand* deadCmd = dynamic_cast<DeadCommand*>(command);
        Plant* plant = deadCmd->getPlant();
        createDeleteQuery(plant->getId(), plant->getName(), plant->getMaturityState());
        // TODO: Figure out how the DeleteQuery works

    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}