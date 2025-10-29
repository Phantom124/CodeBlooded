#ifndef PRICESTRATEGIES_H
#define PRICESTRATEGIES_H

class PriceStrategies {
    public:
        PriceStrategies() = default;
        virtual ~PriceStrategies() {}   

        virtual double apply(double basePrice) = 0;
};
#endif
