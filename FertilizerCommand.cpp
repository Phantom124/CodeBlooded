#include "FertilizerCommand.h"
#include <stdexcept>

FertilizerCommand::FertilizerCommand(Plant *plant)
    : PlantCommand(FERTILIZER, plant){}

void FertilizerCommand::execute(){
    if (plant == nullptr){
        throw std::runtime_error("Attempted to process data with a null pointer.");
    }
    plant->fertilizePlant();
}