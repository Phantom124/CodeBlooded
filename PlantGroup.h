#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "PlantComponent.h"
#include <string>
#include <vector>

class PlantGroup : public PlantComponent
{
private:
	double price;
	std::string name;
	std::vector<PlantComponent *> plants;

	public:
		PlantGroup();
		virtual ~PlantGroup();
	  virtual double getPrice();
	  virtual std::string getName();
    std::vector<PlantComponent *> getPlants();
		void addPlantComponent(PlantComponent* plantComponent);
		std::vector<PlantComponent*> getPlantComponents();
    void removePlantComponent(PlantComponent *plantComponent);
};

#endif
