#include "DeadHandler.h"
#include "DeadCommand.h" 

#include <stdexcept>

DeadHandler::DeadHandler(){}

DeadHandler::~DeadHandler(){
}

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr");
    }

    if (isAvailable == true && command->getType() == DEAD){//First: Are you available //Second: Is this a dead command
        isAvailable = false;
        //Remove the dead plant from the queue
        DeadCommand* deadCmd = dynamic_cast<DeadCommand*>(command);
        Plant* plant = deadCmd->getPlant();
        string id = std::to_string(plant->getPlantId());
        createDeleteQuery(id, plant->getName(), plant->getMaturityStateName());
        // TODO: Figure out how the DeleteQuery works

    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}