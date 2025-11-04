/**
 * @file DeadCommand.h
 * @brief DeadCommand.h — Header and declarations for the DeadCommand.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

	DeadCommand(Plant* plant);
	virtual ~DeadCommand();
	virtual void execute();
	Plant* getPlant();  	
};

#endif
