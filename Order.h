#ifndef ORDER_H
#define ORDER_H

#include "Plant.h"
#include "PlantComponent.h"
#include "PriceStrategies.h"
#include "PlantGroup.h"
#include <string>

class Order
{
private:
	PlantGroup *plantGroup;
	PriceStrategies *priceStrategy;
	std::string receiptID;

public:
	Order(PlantGroup *plantGroup);
	~Order();
	double getPrice();
	std::string getName();
	void printOrder();
	void addToOrder(Plant *plant);
	void setPriceStrategy(PriceStrategies *priceStrategy);
	void applyPriceStrategy();
	std::string getReceiptID();
};

#endif
