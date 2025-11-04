/**
 * @file DeadHandler.cpp
 * @brief DeadHandler.cpp — Header and declarations for the DeadHandler.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "DeadHandler.h"
#include "DeadCommand.h"
#include "QueryProduct.h"
#include "QueueIterator.h"
#include <stdexcept>
#include <iostream>

DeadHandler::DeadHandler() {}

DeadHandler::~DeadHandler(){
}

/**
 * @brief Execute the function's primary operation.
 * @param *command TODO 
 * @param staffSys The staffSys parameter used by the function.
 */

void DeadHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr" 
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param command The command parameter used by the function.
 */

        DeadCommand *deadCmd = dynamic_cast<DeadCommand *>(command);
        Plant *plant = deadCmd->getPlant();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant->getPlantId()
 */

        string id = std::to_string(plant->getPlantId());
        int intId = plant->getPlantId();

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param id The id parameter used by the function.
 * @param plant->getName() 
 * @param plant->getMaturityStateName()
 */

        QueryProduct* qp = createDeleteQuery(id, plant->getName(), plant->getMaturityStateName());
        if (qp){
            qp->execute();
        }
        delete command;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param staffSys The staffSys parameter used by the function.
 */

        QueueIterator it(staffSys);
/**
 * @brief Execute the function's primary operation.
 * @param intId The intId parameter used by the function.
 */

        it.deleteAllWithId(intId);
    } else {
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

        StaffHandler::handleRequest(command, staffSys);
    }
}
