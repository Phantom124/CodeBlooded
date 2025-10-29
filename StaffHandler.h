#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "QueryBuilder.h"
#include "Command.h"
#include <string>

using namespace std;

class QueryBuilder;
class QueryProduct;
class StaffSystem;

class StaffHandler {
	protected:
		StaffHandler* successor;
		QueryBuilder* queryBuilder;
		bool isBusy;
	public:
		StaffHandler();
		virtual void handleRequest(Command* command, StaffSystem* staffSys);
		void setSuccessor(StaffHandler* successor);
		QueryProduct createSelectQuery(string plantID, string plantType, string maturityState);
		QueryProduct createInsertQuery(string plantID, string plantType, string maturityState);
		QueryProduct createDeleteQuery(string plantID, string plantType, string maturityState);
		void resetBusy();
		void setQueryBuilder(QueryBuilder* qb);
};

#endif