#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include "StaffHandler.h"
#include <string>

class WaterHandler : public StaffHandler {
	public:
		WaterHandler(StaffSystem* sys);
		void handleRequest(Command* command);
	};

#endif
