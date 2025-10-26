#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H

#include <string>
#include "Command.h"
#include "Plant.h"

class PlantCommand : public Command {

protected:
	Plant* plant;
	std::string type;

public:
	PlantCommand(const std::string& type, Plant* plant);
	virtual void execute() = 0;
};

#endif
