#include "Sunflower.h"

Sunflower::Sunflower()
    : Plant() // use default Plant ctor like Cactus/Rose
{
    this->type = "Sunflower";
    this->price = 25;
    this->waterRetention = 0.72;
    this->lowWaterLevel = 55;
    this->fertilizerRetention = 0.85;
    this->lowFertilizerLevel = 20;
}

Sunflower::~Sunflower() {}

std::string Sunflower::getName() {
    return "Sunflower";
}
