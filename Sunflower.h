#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include <string>

class Sunflower : public Plant {
	private:
		std::string name;
		double price;

	public:
		Sunflower();
		double getPrice();
		std::string getName();
		void print();
		void add(Plant* extra);
};

#endif
