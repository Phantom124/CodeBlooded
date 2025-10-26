#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    public:
        Item(std::string plantID, std::string plantType, std::string maturityState);

        std::string getPlantID();
        std::string getPlantType();
        std::string getMaturityState();

        std::string toString();

    private:
        std::string plantID;
        std::string plantType;
        std::string maturityState;
};

#endif