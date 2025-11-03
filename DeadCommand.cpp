#include "DeadCommand.h"
#include <stdexcept>

DeadCommand::DeadCommand(Plant *plant): PlantCommand(DEAD, plant){}

DeadCommand::~DeadCommand()
{
}

void DeadCommand::execute(){
    if (plant == nullptr){
        throw std::runtime_error("Attempted to process data with a null pointer.");
    }
    //Still gotta add this functionality
    
}

Plant *DeadCommand::getPlant(){
    return this->plant;//Jared forgot to define this
}
