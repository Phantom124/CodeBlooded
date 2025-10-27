#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant
{
private:
	std::string name;
	double price;

public:
	Sunflower();
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
	virtual void add(Plant *extra) {};
};

#endif
