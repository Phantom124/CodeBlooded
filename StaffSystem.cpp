#include "StaffSystem.h"
#include "StaffHandler.h"

StaffSystem::StaffSystem(StaffHandler* staff){
    staffHandler = staff;
}

QueueIterator StaffSystem::createIterator(){
    QueueIterator out(this);
    return out;
}

void StaffSystem::attemptCommand(Command *cmd){
    if (!cmd || !staffHandler){
        return;
        throw "Command is null or staffHandler is nullptr";
    }

    this->staffHandler->handleRequest(cmd, this);
}
