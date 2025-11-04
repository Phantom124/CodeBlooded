/**
 * @file Item.h
 * @brief Item.h — Header and declarations for the Item.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef ITEM_H
#define ITEM_H

#include "Plant.h"
#include <string>

class Item{
    public:
/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 * @param plantType The plantType parameter used by the function.
 * @param maturityState The maturityState parameter used by the function.
 */

        Item(std::string plantID, std::string plantType, std::string maturityState);

        std::string getPlantID();
        std::string getPlantType();
        std::string getMaturityState();

        std::string toString();

    private:
        std::string plantID;
        std::string plantType;
        std::string maturityState;

        Plant* plantReference;

};

#endif
