#include "DeadHandler.h"
#include "DeadCommand.h"
#include "QueryProduct.h"
#include "QueueIterator.h"
#include <stdexcept>
#include <iostream>

DeadHandler::DeadHandler() {}

DeadHandler::~DeadHandler(){
}

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr");
    }
    else if (staffSys == nullptr)
    {
        throw std::invalid_argument("StaffSystem is a nullptr");
    }

    if (isAvailable == true && command->getType() == DEAD){//First: Are you 1available //Second: Is this a dead command
        // cout << "DeadHandler: Handling dead plant command..." << std::endl;
        isAvailable = false;
        // Remove the dead plant from the queue
        DeadCommand *deadCmd = dynamic_cast<DeadCommand *>(command);
        Plant *plant = deadCmd->getPlant();
        string id = std::to_string(plant->getPlantId());
        int intId = plant->getPlantId();

        // QueryProduct* qp = createDeleteQuery(id, plant->getName(), plant->getMaturityStateName());
        // if (qp){
        //     qp->execute();
        // }
        // delete command;

        // QueueIterator it(staffSys);
        // it.deleteAllWithId(intId);
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}