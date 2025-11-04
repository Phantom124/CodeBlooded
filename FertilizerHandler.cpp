/**
 * @file FertilizerHandler.cpp
 * @brief FertilizerHandler.cpp — Header and declarations for the FertilizerHandler.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "FertilizerHandler.h"

#include <stdexcept>
#include <iostream>

FertilizerHandler::FertilizerHandler() {
    cout << "Creating Fertilizer Handler" << endl;
}

FertilizerHandler::~FertilizerHandler(){
}

/**
 * @brief Execute the function's primary operation.
 * @param *command 
 * @param staffSys The staffSys parameter used by the function.
 */

void FertilizerHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr." 
 */

        throw std::invalid_argument("Command is a nullptr.");
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    } else if (staffSys == nullptr){


        throw std::invalid_argument("StaffSys is a nullptr.");
    }

    if (isAvailable == true && command->getType() == FERTILIZER){//First: Are you available //Second: Is this a fertilizer command
        isAvailable = false;
        command->execute();
        delete command;
    } else {
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

        StaffHandler::handleRequest(command, staffSys);
    }
}
