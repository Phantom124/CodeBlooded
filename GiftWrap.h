/**
 * @file GiftWrap.h
 * @brief GiftWrap.h — Header and declarations for the GiftWrap.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef GIFT_WRAP_H
#define GIFT_WRAP_H

#include "PlantDecorator.h"
#include <string>

class GiftWrap : public PlantDecorator
{

public:
    GiftWrap();
    ~GiftWrap() = default;
    virtual double getPrice();
    virtual std::string getName();
    virtual void print();
};

#endif
