/**
 * @file FertilizerMonitor.cpp
 * @brief FertilizerMonitor.cpp — Header and declarations for the FertilizerMonitor.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "FertilizerMonitor.h"
#include <iostream>
#include "Plant.h"
#include "FertilizerCommand.h"
FertilizerMonitor::FertilizerMonitor(){
    this->type = "FertilizerMonitor";
}

FertilizerMonitor::~FertilizerMonitor(){}

/**
 * @brief Execute the function's primary operation.
 * @param *plant
 */

void FertilizerMonitor::update(Plant *plant){
    if(!plant){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param pointer" 
 */

        throw std::invalid_argument("FertilizerMonitor got a null plant pointer");
    }
    if(plant->getFertilizerStateName() != "NonFertilized"){
            return; // No action needed
    }
    
    if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
        // std::cout<< "Fertilizer Monitor Recieved Update: Sending to Staff System.\n";
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */

        FertilizerCommand* command = new FertilizerCommand(plant);//MAKE FERTILIZER COMMAND CORRECTLY
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 */

        staffSystem->attemptCommand(command);
    }
    
    
}
