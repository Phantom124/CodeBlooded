#include "SalesHandler.h"
#include <stdexcept>

SalesHandler::SalesHandler(){}

void SalesHandler::handleRequest(Command *cmd, StaffSystem* staffSys){
    if (cmd == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSys is a nullptr.");
    }

    if (cmd->getType() == GET_PLANT){
        isBusy = false;
        cmd->execute();
        //TODO: check whether there was anything else?
    } else {
        StaffHandler::handleRequest(cmd, staffSys);
    }

}
