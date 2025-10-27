#include "SalesHandler.h"

SalesHandler::SalesHandler(){}

void SalesHandler::handleRequest(Command *cmd, StaffSystem* staffSys){
    if (cmd == nullptr){
        throw "Command is nullptr.";
    } else if (staffSys == nullptr){
        throw "StaffSys is nullptr";
    }

    if (cmd->getType() == GET_PLANT){
        cmd->execute();

        //TODO: check whether there was anything else?
    } else {
        StaffHandler::handleRequest(cmd, staffSys);
    }

}
