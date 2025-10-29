#include "PlantCommand.h"


PlantCommand::PlantCommand(cmdType type, Plant *plant): Command(type) {
    if(plant == nullptr){
        throw std::invalid_argument("Plant cannot be null when making plant Command");
    }
    this->plant = plant;
}

Plant *PlantCommand::getPlant()
{
    return this->plant;
}
