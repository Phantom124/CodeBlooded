#include "WaterHandler.h"

WaterHandler::WaterHandler(StaffSystem *sys) 
    : StaffHandler(sys) {}

void WaterHandler::handleRequest(Command *command){
    if (command->getType() == WATER){
        command->execute();
    } else {
        StaffHandler::handleRequest(command);
    }
}
