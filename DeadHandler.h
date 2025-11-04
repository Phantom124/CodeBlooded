/**
 * @file DeadHandler.h
 * @brief DeadHandler.h — Header and declarations for the DeadHandler.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef DEADHANDLER_H
#define DEADHANDLER_H

#include "StaffHandler.h"
#include <string>

class DeadHandler : public StaffHandler {
	public:
		DeadHandler();
		virtual ~DeadHandler();
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

		void handleRequest(Command* command, StaffSystem* staffSys);
};

#endif
