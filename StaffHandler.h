#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include "Command.h"
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
		virtual void handleRequest(Command* command, StaffSystem* staffSys);
		void setSuccessor(StaffHandler* successor);
		QueryProduct* createSelectQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createSelectQuery(Plant* selectPlant);

		QueryProduct* createInsertQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createInsertQuery(Plant* insertPlant);

		QueryProduct* createDeleteQuery(string plantID, string plantType, string maturityState);
		QueryProduct* createDeleteQuery(Plant* deletePlant);

		void resetAvailable();
		void setQueryBuilder(QueryBuilder* qb);
};

#endif
