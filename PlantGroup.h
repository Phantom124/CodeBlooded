#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "PlantComponent.h"
#include <string>
#include <vector>

class PlantGroup : public PlantComponent {
	private:
		double price;
		std::string name;
		std::vector<PlantComponent*> plants;

	public:
		PlantGroup();
		~PlantGroup();
		double getPrice();
		std::string getName();
		void addPlantComponent(PlantComponent* plantComponent);
};

#endif
