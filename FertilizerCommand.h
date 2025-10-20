#ifndef FERTILIZERCOMMAND_H
#define FERTILIZERCOMMAND_H

class FertilizerCommand : PlantCommand {

protected:
	Plant* plant;
	String type;

public:
	FertilizerCommand(String type, Plant* plant);
};

#endif
