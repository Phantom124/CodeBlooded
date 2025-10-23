#ifndef RIBBON_H
#define RIBBON_H

#include "PlantDecorator.h"
#include <string>

class Ribbon : public PlantDecorator {


public:
	Ribbon();
	~Ribbon();
	double getPrice();
	std::string getName();
	void print();
};

#endif
