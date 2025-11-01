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

class StaffHandler {//WHY IS THIS NOT ABSTRACT???
	protected:
		StaffHandler* successor;
		QueryBuilder* queryBuilder;
		bool isAvailable;
	public:
		StaffHandler();
		virtual ~StaffHandler() = default;
		virtual void handleRequest(Command* command, StaffSystem* staffSys);
		void setSuccessor(StaffHandler* successor);
		StaffHandler* getSuccessor();
		QueryProduct* createSelectQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createInsertQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createDeleteQuery(string plantID, string plantType, string maturityState);
		void resetAvailable();
		void setQueryBuilder(QueryBuilder* qb);
		void printHandlers();
};

#endif

