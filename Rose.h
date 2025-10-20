#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include <string>

class Rose : public Plant {
	private:
		std::string name;
		double price;

	public:
		Rose();
		double getPrice();
		std::string getName();
		void print();
		void add(Plant* extra);
};

#endif
