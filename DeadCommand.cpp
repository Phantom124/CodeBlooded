#include "DeadCommand.h"

DeadCommand::DeadCommand(const std::string &type, Plant *plant)
    : PlantCommand(type, plant){}

void DeadCommand::execute(){
    //Still gotta add this functionality
}