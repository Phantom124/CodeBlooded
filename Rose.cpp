/**
 * @file Rose.cpp
 * @brief Rose.cpp — Header and declarations for the Rose.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Rose.h"
#include <string>

Rose::Rose()
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "Rose" TODO - describe parameter
 * @param 20 The 20 parameter used by the function.
 * @param 0.85 TODO - describe parameter
 * @param 30 The 30 parameter used by the function.
 * @param 0.60 TODO - describe parameter
 * @param 70 The 70 parameter used by the function.
 */

  : Plant("Rose", 20, 0.85, 30, 0.60, 70) {}


/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param state The state parameter used by the function.
 * @param waterLevel The waterLevel parameter used by the function.
 * @param fertilizerLevel The fertilizerLevel parameter used by the function.
 */

// Rose::Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     // this->state = state;
//     // this->waterLevel = waterLevel;
//     // this->fertilizerLevel = fertilizerLevel;
// }

Rose::~Rose(){}



// std::string Rose::getName(){
//     return "Rose";
// }
