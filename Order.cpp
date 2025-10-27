#include "Order.h"

Order::Order(PlantGroup *plantGroup) : plantGroup(plantGroup) {
    static unsigned long long counter = 0;
    receiptID = "RCPT-" + std::to_string(++counter);
}

OrderMemento* Order::createMemento(){
    return new OrderMemento(plantGroup->getPlantComponents(), this->getPrice(), receiptID);
}

Receipt* Order::generateReceipt(){
    return new Receipt(receiptID, this->getPrice(), this->generateInfo());
}

std::string Order::getReceiptID() const{
    return receiptID;
}

std::string Order::generateInfo(){
    std::string info = "";

    if (!plantGroup) return info;

    for (size_t i = 0; i < plantGroup->getPlantComponents().size(); ++i) {
        auto p = plantGroup->getPlantComponents()[i];
        if (!p) continue;
        info += p->getName();
        info += " : R";
        info += std::to_string(p->getPrice());
        if (i + 1 < plantGroup->getPlantComponents().size()) info += "\n";
    }
    return info;
}