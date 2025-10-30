#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>


class PlantDecorator : public Plant {
	public:
		Plant* myPlant;
		PlantDecorator();
		~PlantDecorator();
		void add(Plant* extra);
		void print();
		double getPrice();
		std::string getName();
};

#endif