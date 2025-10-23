#ifndef PLANTMONITOR_H
#define PLANTMONITOR_H

#include "Plant.h"
#include "StaffHandler.h"

class PlantMonitor {
	private:
		Plant* subject;
		StaffHandler* chain;

	public:
		void update();
};

#endif
