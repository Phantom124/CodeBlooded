/**
 * @file SalesHandler.cpp
 * @brief SalesHandler.cpp — Header and declarations for the SalesHandler.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "SalesHandler.h"
#include <stdexcept>

SalesHandler::SalesHandler(){}

/**
 * @brief Execute the function's primary operation.
 * @param *cmd TODO - describe parameter
 * @param staffSys The staffSys parameter used by the function.
 */

void SalesHandler::handleRequest(Command *cmd, StaffSystem* staffSys){
    if (cmd == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr." TODO - describe parameter
 */

        throw std::invalid_argument("Command is a nullptr.");
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    } else if (staffSys == nullptr){


        throw std::invalid_argument("StaffSys is a nullptr.");
    }

    if (cmd->getType() == GET_PLANT){
        isAvailable = false;
        cmd->execute();
        //TODO: check whether there was anything else?
    } else {
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

        StaffHandler::handleRequest(cmd, staffSys);
    }

}
