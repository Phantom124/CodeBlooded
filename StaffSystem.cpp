#include "StaffSystem.h"
#include "StaffHandler.h"

#include <stdexcept>

StaffSystem::StaffSystem(StaffHandler* staff){
    staffHandler = staff;
}

void StaffSystem::setHandler(StaffHandler *staff){
    if (this->staffHandler != nullptr){
        delete this->staffHandler;
        this->staffHandler = nullptr;
    }
    this->staffHandler = staff;
}

QueueIterator StaffSystem::createIterator(){
    QueueIterator out(this);
    return out;
}

void StaffSystem::attemptCommand(Command *cmd){
    if (!cmd){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (!staffHandler) {
        throw std::invalid_argument("staffHandler is a nullptr.");
    }

    this->staffHandler->handleRequest(cmd, this);
}
