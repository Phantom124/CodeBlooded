/**
 * @file WaterCommand.h
 * @brief WaterCommand.h — Header and declarations for the WaterCommand.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include <string>
#include "PlantCommand.h"
#include "Plant.h"

class WaterCommand : public PlantCommand {

protected:
	// Plant* plant;
	// std::string type;

public:
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

	WaterCommand(Plant* plant);
	~WaterCommand();
	virtual void execute();
};

#endif
