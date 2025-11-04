/**
 * @file Receipt.h
 * @brief Receipt.h — Header and declarations for the Receipt.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <chrono>

class Receipt {
    private:
        std::string receiptID;
        std::string orderInfo;
        double orderPrice;
        std::chrono::system_clock::time_point orderDate;
        bool isValid;

    public:
/**
 * @brief Execute the function's primary operation.
 * @param receiptID The receiptID parameter used by the function.
 * @param orderPrice The orderPrice parameter used by the function.
 * @param info The info parameter used by the function.
 */

        Receipt(const std::string& receiptID, double orderPrice, const std::string& info);
        std::string getReceiptID() const;
        std::string getOrderInfo() const;
        double getOrderPrice() const;
        std::chrono::system_clock::time_point getOrderDate() const;
        void printReceipt() const;
        bool validateReceipt();
        bool getIsValid() const;
};

#endif
