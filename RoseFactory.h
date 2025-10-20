#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H

#include "PlantFactory.h"
#include "Plant.h"

class RoseFactory : public PlantFactory {
	public:
		Plant* createRose();
};

#endif
