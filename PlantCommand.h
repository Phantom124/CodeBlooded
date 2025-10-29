#include "Command.h"
#include <stdexcept>
#include "Plant.h"

class PlantCommand : public Command {
protected:
    Plant* plant;
    cmdType type;

public:
    PlantCommand(cmdType type, Plant* plant);
    virtual void execute() = 0;
	Plant* getPlant();

    // Prevent accidental copies that lose the plant pointer
    PlantCommand(const PlantCommand&) = delete;
    PlantCommand& operator=(const PlantCommand&) = delete;
};
