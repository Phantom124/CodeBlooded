#include "StaffSystem.h"
#include "StaffHandler.h"
#include <iostream>
#include <stdexcept>
#include "PlantCommand.h"

StaffSystem::StaffSystem(GreenHouseInventory* inventory, QueryBuilder* queryBuilder) : inventory(inventory), queryBuilder(queryBuilder) {
    staffHandler = nullptr;
}

StaffSystem::~StaffSystem(){
    if (!staffHandler)
        return;

    // while (staffHandler) {
    //     StaffHandler* temp = staffHandler;
    //     staffHandler = staffHandler->getSuccessor();
    //     delete temp;
    // }
    staffHandler = nullptr;

    QueueIterator it = createIterator();
    it.deleteQueue();
}

// void StaffSystem::setHandler(StaffHandler *staff){
//     if (this->staffHandler != nullptr){
//         delete this->staffHandler;
//         this->staffHandler = nullptr;
//     }
//     this->staffHandler = staff;
// }

void StaffSystem::timeElapsed(){
    if(this->staffHandler != nullptr){
        this->staffHandler->resetAvailable();
    }

    QueueIterator it = createIterator();
    it.emptyQueue(this->staffHandler);
    
}

void StaffSystem::addHandler(StaffHandler *staff)
{
    if (staff == nullptr){
        throw std::invalid_argument("Cannot add staff handler is a nullptr.");
    }
    cout << "Adding StaffHandler to StaffSystem..." << std::endl;
    if (this->staffHandler == nullptr){
        cout << "This is the first staff handler being added." << std::endl;
        this->staffHandler = staff;
        return;
    }
    cout << "Setting new staff handler as successor to existing handler." << std::endl;
    staff->setSuccessor(this->staffHandler);
    this->staffHandler = staff;

    // StaffHandler* current = this->staffHandler;
    // staff->setSuccessor(current);
}

QueueIterator StaffSystem::createIterator(){
    QueueIterator out(this);
    return out;
}

void StaffSystem::attemptCommand(Command *cmd){
    if (!cmd){
        throw std::invalid_argument("Command is a nullptr.");
    }

    PlantCommand* pc = dynamic_cast<PlantCommand*>(cmd);
    if(pc){
        // std::cout << "DEBUG: StaffSystem received command for plant @" << static_cast<void*>(pc->getPlant()) << std::endl;
    } else {
        // std::cout << "DEBUG: StaffSystem received non-Plant command @" << cmd << std::endl;
    }

    if (!staffHandler){//No staff handler, attempt to put in queue
        // throw std::invalid_argument("staffHandler is nullptr.");
        //PUT COMMAND IN QUEUE DIRECTLY
        QueueIterator it = this->createIterator();
        it.enqueue(cmd);
        return;
    }
    this->staffHandler->handleRequest(cmd, this);
}
