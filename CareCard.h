#ifndef CARE_CARD_H
#define CARE_CARD_H

#include "PlantDecorator.h"
#include <string>

class CareCard : public PlantDecorator
{

public:
    CareCard();
    ~CareCard() = default;
    virtual double getPrice();
    virtual std::string getName();
    virtual void print();
};

#endif
