/**
 * @file test_decorator_pattern.cpp
 * @brief Unit tests for Decorator Pattern implementation
 * 
 * Tests PlantDecorator and its concrete implementations (GiftWrap, RedPot, Ribbon, Scent).
 */

#include <gtest/gtest.h>
#include "Plant.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "PlantDecorator.h"
#include "GiftWrap.h"
#include "RedPot.h"
#include "Ribbon.h"
#include "Scent.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class DecoratorPatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    Plant* basePlant;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        basePlant = factory->createPlant();
    }
    
    void TearDown() override {
        delete basePlant;
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(DecoratorPatternTest, GiftWrapDecorator) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* decorated = new GiftWrap(basePlant);
    
    EXPECT_GT(decorated->getPrice(), basePrice) << "GiftWrap should increase price";
    EXPECT_NE(decorated->getDescription().find("Gift Wrap"), std::string::npos) 
        << "Description should include GiftWrap";
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, RedPotDecorator) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* decorated = new RedPot(basePlant);
    
    EXPECT_GT(decorated->getPrice(), basePrice) << "RedPot should increase price";
    EXPECT_NE(decorated->getDescription().find("Red Pot"), std::string::npos) 
        << "Description should include RedPot";
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, RibbonDecorator) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* decorated = new Ribbon(basePlant);
    
    EXPECT_GT(decorated->getPrice(), basePrice) << "Ribbon should increase price";
    EXPECT_NE(decorated->getDescription().find("Ribbon"), std::string::npos) 
        << "Description should include Ribbon";
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, ScentDecorator) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* decorated = new Scent(basePlant);
    
    EXPECT_GT(decorated->getPrice(), basePrice) << "Scent should increase price";
    EXPECT_NE(decorated->getDescription().find("Scent"), std::string::npos) 
        << "Description should include Scent";
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, MultipleDecorators) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* decorated = new GiftWrap(basePlant);
    decorated = new Ribbon(decorated);
    decorated = new RedPot(decorated);
    decorated = new Scent(decorated);
    
    EXPECT_GT(decorated->getPrice(), basePrice) << "Multiple decorators should increase price";
    
    std::string description = decorated->getDescription();
    EXPECT_NE(description.find("Gift Wrap"), std::string::npos);
    EXPECT_NE(description.find("Ribbon"), std::string::npos);
    EXPECT_NE(description.find("Red Pot"), std::string::npos);
    EXPECT_NE(description.find("Scent"), std::string::npos);
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, DecoratorOrderMatters) {
    PlantComponent* order1 = new GiftWrap(basePlant);
    order1 = new RedPot(order1);
    
    Plant* basePlant2 = factory->createPlant();
    PlantComponent* order2 = new RedPot(basePlant2);
    order2 = new GiftWrap(order2);
    
    // Both should have the same total price
    EXPECT_DOUBLE_EQ(order1->getPrice(), order2->getPrice()) 
        << "Decorator order shouldn't affect total price";
    
    delete order1;
    delete order2;
}

TEST_F(DecoratorPatternTest, DecoratorPreservesUnderlyingPlant) {
    PlantComponent* decorated = new GiftWrap(basePlant);
    decorated = new RedPot(decorated);
    
    // Should still be able to access plant operations
    EXPECT_NO_THROW(decorated->getMaturityState());
    EXPECT_NO_THROW(decorated->getPlantType());
    
    delete decorated;
}

TEST_F(DecoratorPatternTest, DecoratorsPriceAccumulation) {
    double basePrice = basePlant->getPrice();
    
    PlantComponent* withGiftWrap = new GiftWrap(basePlant);
    double priceAfterGiftWrap = withGiftWrap->getPrice();
    
    PlantComponent* withRibbon = new Ribbon(withGiftWrap);
    double priceAfterRibbon = withRibbon->getPrice();
    
    EXPECT_GT(priceAfterGiftWrap, basePrice);
    EXPECT_GT(priceAfterRibbon, priceAfterGiftWrap);
    
    delete withRibbon;
}
