#include "WaterCommand.h"

WaterCommand::WaterCommand(const cmdType type, Plant *plant)
    : PlantCommand(type, plant){}

void WaterCommand::execute(){
    plant->waterPlant();
}