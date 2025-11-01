#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

#include "StaffHandler.h"
#include <string>

class FertilizerHandler : public StaffHandler {
	public:
		FertilizerHandler();
		virtual ~FertilizerHandler();
		void handleRequest(Command* command, StaffSystem* staffSys);
};

#endif
