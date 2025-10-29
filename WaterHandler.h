#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include "StaffHandler.h"
#include <string>

class WaterHandler : public StaffHandler {
	public:
		WaterHandler();
		virtual void handleRequest(Command* command, StaffSystem* staffSys);
	};

#endif
