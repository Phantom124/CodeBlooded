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