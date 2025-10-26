#include "WaterCommand.h"

WaterCommand::WaterCommand(const std::string &type, Plant *plant)
    : PlantCommand(type, plant){}

void WaterCommand::execute(){
    plant->waterPlant();
}