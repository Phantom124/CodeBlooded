#ifndef DEADHANDLER_H
#define DEADHANDLER_H

#include "StaffHandler.h"
#include <string>

class DeadHandler : public StaffHandler {
	public:
		DeadHandler();
		virtual ~DeadHandler();
		void handleRequest(Command* command, StaffSystem* staffSys);
};

#endif
