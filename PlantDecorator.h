#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>


class PlantDecorator : public Plant {
	public:
		Plant* myPlant;
		PlantDecorator(Plant* plant);
		~PlantDecorator();
		void add(Plant* extra);
		void print();
		double getPrice();
		std::string getName();
};

#endif
