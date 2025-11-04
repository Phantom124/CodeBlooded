/**
 * @file PlantCommand.cpp
 * @brief PlantCommand.cpp — Header and declarations for the PlantCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "PlantCommand.h"


/**
 * @brief Execute the function's primary operation.
 * @param type The type parameter used by the function.
 * @param Command
 */

PlantCommand::PlantCommand(cmdType type, Plant *plant): Command(type) {
    if(plant == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Command
 */

        throw std::invalid_argument("Plant cannot be null when making plant Command");
    }
    this->plant = plant;
}

PlantCommand::~PlantCommand()
{
}

Plant *PlantCommand::getPlant()
{
    return this->plant;
}
