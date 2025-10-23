#ifndef SALESHANDLER_H
#define SALESHANDLER_H

#include "StaffHandler.h"
#include <string>

class SalesHandler : public StaffHandler {
	public:
		SalesHandler();
		void setSuccessor(StaffHandler* successor);
		void handleRequest(Command* command);
		void receive(std::string msg);
		void requestAction(std::string action);
};

#endif
