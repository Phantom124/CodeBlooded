/**
 * @file FertilizerCommand.cpp
 * @brief FertilizerCommand.cpp — Header and declarations for the FertilizerCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "FertilizerCommand.h"
#include <stdexcept>

FertilizerCommand::FertilizerCommand(Plant *plant)
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param FERTILIZER The FERTILIZER parameter used by the function.
 * @param plant The plant parameter used by the function.
 */

    : PlantCommand(FERTILIZER, plant){}

void FertilizerCommand::execute(){
    if (plant == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param pointer." 
 */

        throw std::runtime_error("Attempted to process data with a null pointer.");
    }
    plant->fertilizePlant();
}
