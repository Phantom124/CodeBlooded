#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>

class PlantComponent {
	private:
		double price;
		std::string name;

	public:
		double getPrice();
		std::string getName();
		void addPlantComponent(PlantComponent* plantComponent);
};

#endif
