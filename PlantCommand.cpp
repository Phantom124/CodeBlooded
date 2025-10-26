#include "PlantCommand.h"

PlantCommand::PlantCommand(const std::string &type, Plant *plant)
    : Command(type), plant(plant){}

