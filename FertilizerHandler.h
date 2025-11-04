/**
 * @file FertilizerHandler.h
 * @brief FertilizerHandler.h — Header and declarations for the FertilizerHandler.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

#include "StaffHandler.h"
#include <string>

class FertilizerHandler : public StaffHandler {
	public:
		FertilizerHandler();
		virtual ~FertilizerHandler();
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

		void handleRequest(Command* command, StaffSystem* staffSys);
};

#endif
