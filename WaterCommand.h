#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include <string>
#include "PlantCommand.h"
#include "Plant.h"

class WaterCommand : public PlantCommand {

protected:
	Plant* plant;
	std::string type;

public:
	WaterCommand(const cmdType type, Plant* plant);
	virtual void execute();
};

#endif
