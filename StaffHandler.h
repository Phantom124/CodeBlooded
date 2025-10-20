#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "StaffHandler.h"
#include "StaffSystem.h"
#include <string>

class StaffHandler {
	private:
		StaffHandler* successor;
		StaffSystem* staffSys;

	public:
		void handleRequest(Command* command);
		void setSuccessor(StaffHandler* successor);
		StaffHandler();
		void receive(std::string msg);
		void requestAction(std::string action);
};

#endif
