#include "WaterHandler.h"

#include <stdexcept>

WaterHandler::WaterHandler(StaffSystem *sys) {}

void WaterHandler::handleRequest(Command* command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr.");
    }
    
    if (command->getType() == WATER){
        isBusy = false;
        command->execute();
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
