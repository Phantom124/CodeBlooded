#ifndef SCENT_H
#define SCENT_H

#include "PlantDecorator.h"
#include <string>

class Scent : public PlantDecorator
{

public:
    Scent();
    ~Scent() = default;
    virtual double getPrice();
    virtual std::string getName();
    virtual void print();
};

#endif
