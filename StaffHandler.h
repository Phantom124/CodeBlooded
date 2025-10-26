#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "StaffHandler.h"
#include "StaffSystem.h"
#include <string>

using namespace std;

class QueryBuilder;
class QueryProduct;

class StaffHandler {
	private:
		StaffHandler* successor;
		StaffSystem* staffSys;
		QueryBuilder* queryBuilder;

	public:
		StaffHandler(StaffSystem* sys);
		virtual void handleRequest(Command* command) = 0;
		void setSuccessor(StaffHandler* successor);
		QueryProduct* createSelectQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createInsertQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createDeleteQuery(string plantID, string plantType, string maturityState);
		void setQueryBuilder(QueryBuilder* qb);
};

#endif
