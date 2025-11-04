/**
 * @file StaffSystem.cpp
 * @brief StaffSystem.cpp — Header and declarations for the StaffSystem.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "StaffSystem.h"
#include "StaffHandler.h"
#include <iostream>
#include <stdexcept>
#include "PlantCommand.h"

StaffSystem::StaffSystem(){
    staffHandler = nullptr;
}

StaffSystem::~StaffSystem(){
    if (!staffHandler)
        return;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param staffHandler The staffHandler parameter used by the function.
 */

    // while (staffHandler) {
    //     StaffHandler* temp = staffHandler;
    //     staffHandler = staffHandler->getSuccessor();
    //     delete temp;
    // }
    staffHandler = nullptr;

    QueueIterator it = createIterator();
    it.deleteQueue();
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param *staff TODO - describe parameter
 */

// void StaffSystem::setHandler(StaffHandler *staff){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ! TODO - describe parameter
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param this->staffHandler TODO - describe parameter
 */

    it.emptyQueue(this->staffHandler);
    
}

void StaffSystem::addHandler(StaffHandler *staff)
{
    if (staff == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr." TODO - describe parameter
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param current The current parameter used by the function.
 */

    // staff->setSuccessor(current);
}

QueueIterator StaffSystem::createIterator(){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param this The this parameter used by the function.
 */

    QueueIterator out(this);
    return out;
}

/**
 * @brief Execute the function's primary operation.
 * @param *cmd TODO - describe parameter
 */

void StaffSystem::attemptCommand(Command *cmd){
    if (!cmd){


        throw std::invalid_argument("Command is a nullptr.");
    }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param cmd The cmd parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 */

        it.enqueue(cmd);
        return;
    }
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 * @param this The this parameter used by the function.
 */

    this->staffHandler->handleRequest(cmd, this);
}
