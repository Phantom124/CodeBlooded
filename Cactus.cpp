#include "Cactus.h"

Cactus::Cactus()
    : Plant("Cactus",        // type
            15,              // price
            0.95,            // waterRetention
            15,              // lowWaterLevel
            0.90,            // fertilizerRetention
            10)              // lowFertilizerLevel
{
    // If you need additional cactus-specific setup, put it here.
}

Cactus::~Cactus() {}

// std::string Cactus::getName() {
//     return "Cactus";
// }
