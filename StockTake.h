#ifndef STOCKTAKE_H
#define STOCKTAKE_H

#include "PlantSnapshot.h"
#include <string>
#include <vector>

class StockTake {
	private:
		std::vector<PlantSnapshot*> plantSnapshots;
		time_t timestamp;
		int totalSnapshots;
		std::string stockTakeID;

	public:
		StockTake(std::string id);
		void addSnapshot(PlantSnapshot* snapshot);
		std::vector<PlantSnapshot*> getSnapshot();
		time_t getTimestamp();
		int getTotalSnapshots();
		std::string getStockTakeID();
};

#endif
