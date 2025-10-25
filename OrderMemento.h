#ifndef ORDER_MEMENTO_H
#define ORDER_MEMENTO_H

#include "Order.h"
#include "PlantComponent.h"
#include <date/time.h>
#include <string>
#include <vector>

class OrderMemento {
	private:
		std::vector<PlantComponent*> plants;
        double orderPrice;
        date::time orderDate;
        std::string receiptID;

	public:
		OrderMemento(std::vector<PlantComponent*> plants, double price, std::string receiptID);
		std::vector<PlantComponent*> getPlants() const;
        double getOrderPrice() const;
        date::time getOrderDate() const;
        std::string getReceiptID() const;
};

#endif