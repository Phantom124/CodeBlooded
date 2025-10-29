#ifndef FERTILIZERCOMMAND_H
#define FERTILIZERCOMMAND_H

#include <string>
#include "PlantCommand.h"
#include "Plant.h"

class FertilizerCommand : public PlantCommand {

protected:
	// Plant* plant;
	// std::string type;

public:
	FertilizerCommand(Plant* plant);
	virtual void execute();
};

#endif
