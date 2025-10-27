#include "FertilizerHandler.h"

FertilizerHandler::FertilizerHandler() {}

void FertilizerHandler::handleRequest(Command *command, StaffSystem* staffSys){
    if (command == nullptr){
        throw "Command is nullptr.";
    } else if (staffSys == nullptr){
        throw "StaffSys is nullptr";
    }

    if (command->getType() == FERTILIZER){
        isBusy = false;
        command->execute();
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
