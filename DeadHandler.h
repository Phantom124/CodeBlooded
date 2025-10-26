#ifndef DEADHANDLER_H
#define DEADHANDLER_H

#include "StaffHandler.h"
#include <string>

class DeadHandler : public StaffHandler {
	public:
		DeadHandler(StaffSystem* sys);
		void handleRequest(Command* command);
};

#endif
