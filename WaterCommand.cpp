/**
 * @file WaterCommand.cpp
 * @brief WaterCommand.cpp — Header and declarations for the WaterCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "WaterCommand.h"
#include <stdexcept>
#include <iostream>
WaterCommand::WaterCommand(Plant *plant)
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param WATER The WATER parameter used by the function.
 * @param plant The plant parameter used by the function.
 */

    : PlantCommand(WATER, plant){}

WaterCommand::~WaterCommand()
{
}

void WaterCommand::execute(){
    // std::cout << "DEBUG: Executing WaterCommand for plant @" << static_cast<void*>(this->plant) << std::endl;
    if(!plant){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant" TODO - describe parameter
 */

        throw std::invalid_argument("WaterCommand tried to execute with null plant");
    }
    plant->waterPlant();
}
