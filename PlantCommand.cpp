#include "PlantCommand.h"

PlantCommand::PlantCommand(cmdType type, Plant *plant)
    : Command(type), plant(plant){}
