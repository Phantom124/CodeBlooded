#include "WaterHandler.h"

WaterHandler::WaterHandler(StaffSystem *sys) {}

void WaterHandler::handleRequest(Command* command, StaffSystem* staffSys){
    if (command == nullptr){
        throw "Command is nullptr.";
    } else if (staffSys == nullptr){
        throw "StaffSys is nullptr";
    }
    
    if (command->getType() == WATER){
        command->execute();
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
