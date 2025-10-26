#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "StaffHandler.h"
#include "StaffSystem.h"
#include "QueryBuilder.h"
#include "QueryProduct.h"
#include <string>

class StaffHandler {
	private:
		StaffHandler* successor;
		StaffSystem* staffSys;

		QueryBuilder* queryBuilder = nullptr;

	public:
		void handleRequest(Command* command);
		void setSuccessor(StaffHandler* successor);
		StaffHandler();
		void receive(std::string msg);
		void requestAction(std::string action);

		QueryProduct createSelectQuery(std::string plantID, std::string plantType, std::string maturityState);
        QueryProduct createInsertQuery(std::string plantID, std::string plantType, std::string maturityState);
        QueryProduct createDeleteQuery(std::string plantID, std::string plantType, std::string maturityState);

		void setQueryBuilder(QueryBuilder* queryBuilder);
};

#endif
