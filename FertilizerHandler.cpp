#include "FertilizerHandler.h"

#include <stdexcept>

FertilizerHandler::FertilizerHandler() {}

FertilizerHandler::~FertilizerHandler(){
}

void FertilizerHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSys is a nullptr.");
    }

    if (isAvailable == true && command->getType() == FERTILIZER){//First: Are you available //Second: Is this a fertilizer command
        isAvailable = false;
        command->execute();
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
