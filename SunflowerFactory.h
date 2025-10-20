#ifndef SUNFLOWERFACTORY_H
#define SUNFLOWERFACTORY_H

#include "PlantFactory.h"
#include "Plant.h"

class SunflowerFactory : public PlantFactory {
	public:
		void createSunflower();
};

#endif
