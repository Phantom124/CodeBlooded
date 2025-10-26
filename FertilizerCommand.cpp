#include "FertilizerCommand.h"

FertilizerCommand::FertilizerCommand(const std::string &type, Plant *plant)
    : PlantCommand(type, plant){}

void FertilizerCommand::execute(){
    plant->fertilizePlant();
}