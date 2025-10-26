#include "PlantCommand.h"

PlantCommand::PlantCommand(const cmdType type, Plant *plant)
    : Command(type), plant(plant){}