#ifndef DEADHANDLER_H
#define DEADHANDLER_H

#include "StaffHandler.h"
#include <string>

class DeadHandler : public StaffHandler {
	public:
		DeadHandler();
		void setSuccessor(StaffHandler* successor);
		void handleRequest(Command* command);
		void receive(std::string msg);
		void requestAction(std::string action);
};

#endif