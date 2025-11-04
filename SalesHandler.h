/**
 * @file SalesHandler.h
 * @brief SalesHandler.h — Header and declarations for the SalesHandler.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef SALESHANDLER_H
#define SALESHANDLER_H

#include "StaffHandler.h"
#include <string>

class SalesHandler : public StaffHandler {
	public:
		SalesHandler();
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

		void handleRequest(Command* cmd, StaffSystem* staffSys);

};

#endif
