#include "FertilizerHandler.h"

#include <stdexcept>

FertilizerHandler::FertilizerHandler() {}

void FertilizerHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSys is a nullptr.");
    }

    if (command->getType() == FERTILIZER){
        isBusy = false;
        command->execute();
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
