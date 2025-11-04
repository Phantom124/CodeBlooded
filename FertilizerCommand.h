/**
 * @file FertilizerCommand.h
 * @brief FertilizerCommand.h — Header and declarations for the FertilizerCommand.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

	FertilizerCommand(Plant* plant);
	virtual void execute();
};

#endif
