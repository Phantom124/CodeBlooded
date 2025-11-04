/**
 * @file DeadCommand.cpp
 * @brief DeadCommand.cpp — Header and declarations for the DeadCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "DeadCommand.h"
#include <stdexcept>

/**
 * @brief Execute the function's primary operation.
 * @param PlantCommand(DEAD TODO - describe parameter
 * @param plant The plant parameter used by the function.
 */

DeadCommand::DeadCommand(Plant *plant): PlantCommand(DEAD, plant){}

DeadCommand::~DeadCommand()
{
}

void DeadCommand::execute(){
    if (plant == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param pointer." 
 */

        throw std::runtime_error("Attempted to process data with a null pointer.");
    }
    //Still gotta add this functionality
    
}

Plant *DeadCommand::getPlant(){
    return this->plant;//Jared forgot to define this
}
