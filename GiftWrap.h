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
