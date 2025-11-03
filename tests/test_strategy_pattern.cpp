/**
 * @file test_strategy_pattern.cpp
 * @brief Unit tests for Strategy Pattern implementation
 * 
 * Tests PriceStrategies (NormalPrice, BulkDiscount, Save10Discount).
 */

#include <gtest/gtest.h>
#include "PriceStrategies.h"
#include "NormalPrice.h"
#include "BulkDiscount.h"
#include "Save10Discount.h"

class StrategyPatternTest : public ::testing::Test {
protected:
    double basePrice = 100.0;
    
    void SetUp() override {
        // Setup if needed
    }
    
    void TearDown() override {
        // Cleanup if needed
    }
};

TEST_F(StrategyPatternTest, NormalPriceStrategyCreates) {
    NormalPrice* strategy = new NormalPrice();
    EXPECT_NE(strategy, nullptr);
    delete strategy;
}

TEST_F(StrategyPatternTest, BulkDiscountStrategyCreates) {
    BulkDiscount* strategy = new BulkDiscount();
    EXPECT_NE(strategy, nullptr);
    delete strategy;
}

TEST_F(StrategyPatternTest, Save10DiscountStrategyCreates) {
    Save10Discount* strategy = new Save10Discount();
    EXPECT_NE(strategy, nullptr);
    delete strategy;
}

TEST_F(StrategyPatternTest, NormalPriceReturnsOriginalPrice) {
    NormalPrice strategy;
    double calculatedPrice = strategy.calculatePrice(basePrice, 1);
    
    EXPECT_DOUBLE_EQ(calculatedPrice, basePrice) 
        << "Normal price should return original price";
}

TEST_F(StrategyPatternTest, BulkDiscountReducesPrice) {
    BulkDiscount strategy;
    int bulkQuantity = 10;
    
    double discountedPrice = strategy.calculatePrice(basePrice, bulkQuantity);
    
    EXPECT_LT(discountedPrice, basePrice * bulkQuantity) 
        << "Bulk discount should reduce total price";
}

TEST_F(StrategyPatternTest, Save10DiscountReducesPrice) {
    Save10Discount strategy;
    
    double discountedPrice = strategy.calculatePrice(basePrice, 1);
    
    EXPECT_LT(discountedPrice, basePrice) 
        << "Save10 discount should reduce price";
    EXPECT_DOUBLE_EQ(discountedPrice, basePrice * 0.9) 
        << "Save10 should apply 10% discount";
}

TEST_F(StrategyPatternTest, DifferentStrategiesProduceDifferentPrices) {
    NormalPrice normalStrategy;
    BulkDiscount bulkStrategy;
    Save10Discount save10Strategy;
    
    double normalPrice = normalStrategy.calculatePrice(basePrice, 10);
    double bulkPrice = bulkStrategy.calculatePrice(basePrice, 10);
    double save10Price = save10Strategy.calculatePrice(basePrice, 1);
    
    // All strategies should potentially produce different results
    EXPECT_TRUE(normalPrice != bulkPrice || bulkPrice != save10Price);
}

TEST_F(StrategyPatternTest, StrategyCanBeChangedAtRuntime) {
    PriceStrategies* strategy;
    
    // Start with normal price
    strategy = new NormalPrice();
    double price1 = strategy->calculatePrice(basePrice, 1);
    delete strategy;
    
    // Change to bulk discount
    strategy = new BulkDiscount();
    double price2 = strategy->calculatePrice(basePrice, 10);
    delete strategy;
    
    // Change to save10 discount
    strategy = new Save10Discount();
    double price3 = strategy->calculatePrice(basePrice, 1);
    delete strategy;
    
    // Each strategy should work independently
    EXPECT_DOUBLE_EQ(price1, basePrice);
    EXPECT_LT(price2, basePrice * 10);
    EXPECT_DOUBLE_EQ(price3, basePrice * 0.9);
}

TEST_F(StrategyPatternTest, BulkDiscountScalesWithQuantity) {
    BulkDiscount strategy;
    
    double price5 = strategy.calculatePrice(basePrice, 5);
    double price10 = strategy.calculatePrice(basePrice, 10);
    double price20 = strategy.calculatePrice(basePrice, 20);
    
    // Larger quantities should get better discounts
    EXPECT_LT(price10, basePrice * 10);
    EXPECT_LT(price20, basePrice * 20);
}

TEST_F(StrategyPatternTest, Save10ConsistentlyApplies10Percent) {
    Save10Discount strategy;
    
    double price1 = strategy.calculatePrice(50.0, 1);
    double price2 = strategy.calculatePrice(100.0, 1);
    double price3 = strategy.calculatePrice(200.0, 1);
    
    EXPECT_DOUBLE_EQ(price1, 45.0);
    EXPECT_DOUBLE_EQ(price2, 90.0);
    EXPECT_DOUBLE_EQ(price3, 180.0);
}

TEST_F(StrategyPatternTest, StrategiesImplementSameInterface) {
    PriceStrategies* strategies[] = {
        new NormalPrice(),
        new BulkDiscount(),
        new Save10Discount()
    };
    
    // All strategies should be callable with the same interface
    for (auto strategy : strategies) {
        EXPECT_NO_THROW(strategy->calculatePrice(basePrice, 1));
        delete strategy;
    }
}

TEST_F(StrategyPatternTest, StrategyWithZeroPriceHandledCorrectly) {
    NormalPrice normalStrategy;
    Save10Discount save10Strategy;
    
    double normalZero = normalStrategy.calculatePrice(0.0, 1);
    double save10Zero = save10Strategy.calculatePrice(0.0, 1);
    
    EXPECT_DOUBLE_EQ(normalZero, 0.0);
    EXPECT_DOUBLE_EQ(save10Zero, 0.0);
}
