#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Receipt::Receipt(const std::string& receiptID, double orderPrice, const std::string& info) 
    : receiptID(receiptID), orderPrice(orderPrice), orderInfo(info), isValid(true) {
    orderDate = std::chrono::system_clock::now();
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

std::chrono::system_clock::time_point Receipt::getOrderDate() const {
    return orderDate;
}

void Receipt::printReceipt() const {
    std::cout << "Receipt ID: " << receiptID << std::endl;
    
    std::time_t time = std::chrono::system_clock::to_time_t(orderDate);
    std::cout << "Order Date: " << std::put_time(std::localtime(&time), "%d/%m/%Y %H:%M:%S") << std::endl;
    
    std::cout << "===========================" << std::endl;
    std::cout << "Order Info: " << orderInfo << std::endl;
    std::cout << "Total Price: R" << orderPrice << std::endl;
    std::cout << "===========================" << std::endl;
}

bool Receipt::validateReceipt() {
    auto now = std::chrono::system_clock::now();
    auto diff = now - orderDate;

    auto hours = std::chrono::duration_cast<std::chrono::hours>(diff).count();
    isValid = (hours <= 168);
    return isValid;
}

bool Receipt::getIsValid() const {
    return isValid;
}
