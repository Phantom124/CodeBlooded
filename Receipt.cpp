#include "Receipt.h"
#include <iostream>

Receipt::Receipt(std::string receiptID, double orderPrice, std::string info) 
    : receiptID(receiptID), orderPrice(orderPrice), orderInfo(info), isValid(true) {
    orderDate = date::current_time();
}

std::string Receipt::getReceiptID() const {
    return receiptID;
}

std::string Receipt::getOrderInfo() const {
    return orderInfo;
}

double Receipt::getOrderPrice() const {
    return orderPrice;
}

date::time Receipt::getOrderDate() const {
    return orderDate;
}

void Receipt::printReceipt() const {
    std::cout << "Receipt ID: " << receiptID << std::endl;
    std::cout << "Order Date: " << date::format("%d/%m/%Y %H:%M:%S", orderDate) << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Order Info: " << orderInfo << std::endl;
    std::cout << "Total Price: R" << orderPrice << std::endl;
    std::cout << "===========================" << std::endl;
}

bool Receipt::validateReceipt() {
    auto now = date::current_time();
    auto diff = now - orderDate;

    auto days = std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;
    isValid = (days <= 7);
    return isValid;
}
