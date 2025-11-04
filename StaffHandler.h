/**
 * @file StaffHandler.h
 * @brief StaffHandler.h — Header and declarations for the StaffHandler.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "Command.h"
// #include "QueryProduct.h"
// #include "QueryBuilder.h"
// #include "StaffSystem.h"
#include <string>

using namespace std;

class QueryBuilder;
class QueryProduct;
class StaffSystem;
class Plant;

class StaffHandler {//WHY IS THIS NOT ABSTRACT???
	protected:
		StaffHandler* successor;
		QueryBuilder* queryBuilder;
		bool isAvailable;
	public:
		StaffHandler();
		virtual ~StaffHandler();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param command The command parameter used by the function.
 * @param staffSys The staffSys parameter used by the function.
 */

		virtual void handleRequest(Command* command, StaffSystem* staffSys);
/**
 * @brief Execute the function's primary operation.
 * @param successor The successor parameter used by the function.
 */

		void setSuccessor(StaffHandler* successor);
		StaffHandler* getSuccessor();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

		QueryProduct* createSelectQuery(string plantID, string plantType, string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param selectPlant The selectPlant parameter used by the function.
 */

		QueryProduct* createSelectQuery(Plant* selectPlant);


		QueryProduct* createInsertQuery(string plantID, string plantType, string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param insertPlant The insertPlant parameter used by the function.
 */

		QueryProduct* createInsertQuery(Plant* insertPlant);


		QueryProduct* createDeleteQuery(string plantID, string plantType, string maturityState);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deletePlant The deletePlant parameter used by the function.
 */

		QueryProduct* createDeleteQuery(Plant* deletePlant);

		void resetAvailable();
/**
 * @brief Execute the function's primary operation.
 * @param qb The qb parameter used by the function.
 */

		void setQueryBuilder(QueryBuilder* qb);
};

#endif
