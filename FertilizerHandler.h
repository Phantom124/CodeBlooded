#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

#include "StaffHandler.h"
#include <string>

class FertilizerHandler : public StaffHandler {
	public:
		FertilizerHandler(StaffSystem* sys);
		void handleRequest(Command* command);
};

#endif
