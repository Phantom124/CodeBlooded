/**
 * @file Sunflower.cpp
 * @brief Sunflower.cpp — Header and declarations for the Sunflower.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Sunflower.h"

Sunflower::Sunflower()
    : Plant("Sunflower", // type
            25.00,       // price
            0.72,        // waterRetention
            55,          // lowWaterLevel
            0.85,        // fertilizerRetention
            20)          // lowFertilizerLevel
{
    // Additional sunflower setup can go here if needed.
}

Sunflower::~Sunflower() {}

// std::string Sunflower::getName()
// {
//     return "Sunflower";
// }
