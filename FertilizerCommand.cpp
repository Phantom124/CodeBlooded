#include "FertilizerCommand.h"

FertilizerCommand::FertilizerCommand(const cmdType type, Plant *plant)
    : PlantCommand(type, plant){}

void FertilizerCommand::execute(){
    plant->fertilizePlant();
}