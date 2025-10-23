#ifndef ORDER_H
#define ORDER_H

#include "Plant.h"
#include "PlantComponent.h"
#include "PriceStrategies.h"
#include <string>

class Order {
	private:
		PlantComponent* plants;
		PriceStrategies* priceStrategy;

	public:
		Order(PlantComponent* plants);
		~Order();
		double getPrice();
		std::string getName();
		void printOrder();
		void addToOrder(Plant* plant);
		void priceStrategy();
};

#endif
