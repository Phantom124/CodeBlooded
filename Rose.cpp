#include "Rose.h"

Rose::Rose()
    : Plant() // use default Plant ctor
{
    this->type = "Rose";
    this->price = 20;
    this->waterRetention = 0.85;
    this->lowWaterLevel = 30;
    this->fertilizerRetention = 0.60;
    this->lowFertilizerLevel = 70;
}

Rose::~Rose() {}

std::string Rose::getName() {
    return "Rose";
}
