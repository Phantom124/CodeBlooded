/**
 * @file WaterHandler.h
 * @brief WaterHandler.h — Header and declarations for the WaterHandler.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include "StaffHandler.h"
#include <string>

class WaterHandler : public StaffHandler {
	public:
		WaterHandler();
		virtual ~WaterHandler();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

		virtual void handleRequest(Command* command, StaffSystem* staffSys);
	};

#endif
