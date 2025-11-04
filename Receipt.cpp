/**
 * @file Receipt.cpp
 * @brief Receipt.cpp — Header and declarations for the Receipt.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Receipt::Receipt(const std::string& receiptID, double orderPrice, const std::string& info) 
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receiptID) TODO - describe parameter
 * @param orderPrice(orderPrice) TODO - describe parameter
 * @param orderInfo(info) TODO - describe parameter
 * @param isValid(true TODO - describe parameter
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param orderDate The orderDate parameter used by the function.
 */

    std::time_t t = std::chrono::system_clock::to_time_t(orderDate);
    std::tm buf;
#if defined(_WIN32) || defined(_WIN64)
/**
 * @brief Execute the function's primary operation.
 * @param &buf TODO - describe parameter
 * @param &t TODO - describe parameter
 */

    localtime_s(&buf, &t);
#else
/**
 * @brief Execute the function's primary operation.
 * @param &t TODO - describe parameter
 * @param &buf TODO - describe parameter
 */

    localtime_r(&t, &buf);
#endif

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param diff).count( TODO - describe parameter
 */

    auto hours = std::chrono::duration_cast<std::chrono::hours>(diff).count();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param < TODO - describe parameter
 */

    isValid = (hours <= 168); // 7 days
    return isValid;
}

bool Receipt::getIsValid() const {
    return isValid;
}
