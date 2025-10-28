#include "DeadHandler.h"
#include "DeadCommand.h" 

#include <stdexcept>

DeadHandler::DeadHandler(){}

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr");
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