#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include "StaffHandler.h"
#include <string>

class WaterHandler : public StaffHandler {
	public:
		void DeadHandler();
		void setSuccessor(StaffHandler* successor);
		void handleRequest(Command* command);
		void receive(std::string msg);
		void requestAction(std::string action);
};

#endif
