#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "PlantGrowthState.h"
#include <string>

class Rose : public Plant
{
private:
	std::string name;
	double price;

public:
	Rose();
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
	virtual void add(Plant *extra) {};
};

#endif
