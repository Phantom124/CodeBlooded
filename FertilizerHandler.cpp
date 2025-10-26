#include "FertilizerHandler.h"

FertilizerHandler::FertilizerHandler(StaffSystem* sys)
    : StaffHandler(sys){}

void FertilizerHandler::handleRequest(Command *command){
    if (command->getType() == FERTILIZER){
        command->execute();
    } else {
        StaffHandler::handleRequest(command);
    }
}
