/**
 * @file DeadMonitor.cpp
 * @brief DeadMonitor.cpp — Header and declarations for the DeadMonitor.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "DeadMonitor.h"
#include <iostream>
#include "Plant.h"
#include "DeadCommand.h"
DeadMonitor::DeadMonitor(){
    this->type = "DeadMonitor";
}

DeadMonitor::~DeadMonitor(){}

/**
 * @brief Execute the function's primary operation.
 * @param *plant 
 */

void DeadMonitor::update(Plant *plant){
    if(plant != nullptr){//Passed in plant is valid
        if(plant->getHealth() == 0){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */

            DeadCommand* command = new DeadCommand(plant);//MAKE DEAD COMMAND CORRECTLY
            if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 */

                staffSystem->attemptCommand(command);
                std::cout<< "Dead Monitor Recieved Update: sending to Staff System.\n";
            }
        }
    }
}
