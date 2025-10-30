#include "Sunflower.h"

Sunflower::Sunflower()
    : Plant("Sunflower",     // type
            25,              // price
            0.72,            // waterRetention
            55,              // lowWaterLevel
            0.85,            // fertilizerRetention
            20)              // lowFertilizerLevel
{
    // Additional sunflower setup can go here if needed.
}

Sunflower::~Sunflower() {}

std::string Sunflower::getName() {
    return "Sunflower";
}
