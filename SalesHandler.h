#ifndef SALESHANDLER_H
#define SALESHANDLER_H

#include "StaffHandler.h"
#include <string>

class SalesHandler : public StaffHandler {
	public:
		SalesHandler();
		void handleRequest(Command* cmd, StaffSystem* staffSys);

};

#endif
