
#include "WaterCommand.h"
#include <stdexcept>

WaterCommand::WaterCommand(Plant *plant)
    : PlantCommand(WATER, plant){}

void WaterCommand::execute(){
    if (plant == nullptr){
        throw std::runtime_error("Attempted to process data with a null pointer.");
    }
    plant->waterPlant();
}
