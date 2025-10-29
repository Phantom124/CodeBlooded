#ifndef DEADCOMMAND_H
#define DEADCOMMAND_H

#include <string>
#include "PlantCommand.h"
#include "Plant.h"

class DeadCommand : public PlantCommand {

protected:
	// Plant* plant;
	// std::string type;

public:
	DeadCommand(Plant* plant);
	virtual void execute();
	Plant* getPlant();  	
};

#endif