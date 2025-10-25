#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <date/time.h>

class Receipt {
    private:
        std::string receiptID;
        std::string orderInfo;
        double orderPrice;
        date::time orderDate;
        bool isValid;

    public:
        Receipt(std::string receiptID, double orderPrice, std::string info);
        std::string getReceiptID() const;
        std::string getOrderInfo() const;
        double getOrderPrice() const;
        date::time getOrderDate() const;
        void printReceipt() const;
        bool validateReceipt();
        bool getIsValid() const;
};

#endif