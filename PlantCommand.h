#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H

#include <string>
#include "Command.h"
#include "Plant.h"

class PlantCommand : public Command {

protected:
	Plant* plant;
	cmdType type;

public:
	PlantCommand(cmdType type, Plant* plant);
	virtual void execute() = 0;
};

#endif
