#include "Receipt.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

Receipt::Receipt(const std::string& receiptID, double orderPrice, const std::string& info)
    : receiptID(receiptID),
      orderInfo(info),
      orderPrice(orderPrice),
      orderDate(std::chrono::system_clock::now()),
      isValid(true) {
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
    std::time_t t = std::chrono::system_clock::to_time_t(orderDate);
    std::tm buf;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&buf, &t);
#else
    localtime_r(&t, &buf);
#endif

    std::cout << "Receipt ID: " << receiptID << std::endl;
    std::cout << "Order Date: " << std::put_time(&buf, "%d/%m/%Y %H:%M:%S") << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Order Info: " << orderInfo << std::endl;
    std::cout << "Total Price: R" << orderPrice << std::endl;
    std::cout << "===========================" << std::endl;
}

bool Receipt::validateReceipt() {
    auto now = std::chrono::system_clock::now();
    auto diff = now - orderDate;
    auto hours = std::chrono::duration_cast<std::chrono::hours>(diff).count();
    isValid = (hours <= 168); // 7 days
    return isValid;
}

bool Receipt::getIsValid() const {
    return isValid;
}
