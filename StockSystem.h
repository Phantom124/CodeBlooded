#ifndef STOCKSYSTEM_H
#define STOCKSYSTEM_H

#include "StockTake.h"
#include <string>
#include <vector>

class StockSystem {
	private:
		std::vector<StockTake*> stockTakeHistory;

	public:
		void addStockTake(StockTake* stockTake);
		StockTake* getLatestStockTake();
		StockTake* getStockTake(time_t timestamp);
		StockTake* getStockTake(std::string id);
		std::vector<StockTake*> getStockTakeHistory();
		void deleteStockTake();
		int getStockTakeCount();
		std::string generateReport();
};

#endif
