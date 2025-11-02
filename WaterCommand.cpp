#include "WaterCommand.h"
#include <stdexcept>
#include <iostream>
WaterCommand::WaterCommand(Plant *plant)
    : PlantCommand(WATER, plant){}

WaterCommand::~WaterCommand()
{
}

void WaterCommand::execute(){
    // std::cout << "DEBUG: Executing WaterCommand for plant @" << static_cast<void*>(this->plant) << std::endl;
    if(!plant){
        throw std::invalid_argument("WaterCommand tried to execute with null plant");
    }
    plant->waterPlant();
}
