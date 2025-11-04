/**
 * @file PlantCommand.h
 * @brief PlantCommand.h — Header and declarations for the PlantCommand.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H
#include "Command.h"
#include <stdexcept>
#include "Plant.h"

class PlantCommand : public Command {
protected:
    Plant* plant;
    cmdType type;

public:
/**
 * @brief Execute the function's primary operation.
 * @param type The type parameter used by the function.
 * @param plant The plant parameter used by the function.
 */

    PlantCommand(cmdType type, Plant* plant);
    virtual ~PlantCommand();
    virtual void execute() = 0;
	Plant* getPlant();

    // Prevent accidental copies that lose the plant pointer
    PlantCommand(const PlantCommand&) = delete;
    PlantCommand& operator=(const PlantCommand&) = delete;
};

#endif // PLANTCOMMAND_H
