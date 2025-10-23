#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

#include "StaffHandler.h"
#include <string>

class FertilizerHandler : public StaffHandler {
	public:
		FertilizerHandler();
		void setSuccessor(StaffHandler* successor);
		void handleRequest(Command* command);
		void receive(std::string msg);
		void requestAction(std::string action);
};

#endif
