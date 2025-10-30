#include "Cactus.h"

Cactus::Cactus()
    : Plant() // use default Plant ctor
{
    // initialize derived-class fields (these are expected to be protected in Plant)
    this->type = "Cactus";
    this->price = 15;
    this->waterRetention = 0.95;
    this->lowWaterLevel = 15;
    this->fertilizerRetention = 0.90;
    this->lowFertilizerLevel = 10;

    // If Plant ctor sets up states/monitors, keep them.
    // Any additional cactus-specific setup can go here.
}

Cactus::~Cactus() {}

std::string Cactus::getName() {
    return "Cactus";
}
