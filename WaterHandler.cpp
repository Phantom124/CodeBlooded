/**
 * @file WaterHandler.cpp
 * @brief Concrete StaffHandler that handles watering commands in the staff chain.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "WaterHandler.h"

#include <stdexcept>
#include <iostream>
using namespace std;

WaterHandler::WaterHandler() {
    cout << "Creating Water Handler" << endl;
}

WaterHandler::~WaterHandler(){
}

/**
 * @brief Handle a command specific to watering: execute if available, otherwise forward.
 * @param command Pointer to the Command to handle (should be a WaterCommand).
 * @param staffSys Pointer to the StaffSystem providing context for enqueuing/forwarding.
 */
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */
void WaterHandler::handleRequest(Command* command, StaffSystem* staffSys){
    if (command == nullptr){
        // Validate inputs
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
        // Validate inputs

        throw std::invalid_argument("StaffSystem is a nullptr.");
    }
    cout << "handle req" << endl;

    if (isAvailable == true && command->getType() == WATER){//First: Are you available //Second: Is this a water command
        cout << "WaterHandler: Handling water command..." << endl;
        isAvailable = false;
        command->execute();
        delete command;
    } else {
        // Not available or not a water command: delegate to base handler logic

        StaffHandler::handleRequest(command, staffSys);
    }
}
