/**
 * @file test_state_pattern.cpp
 * @brief Unit tests for State Pattern implementation
 * 
 * Tests PlantGrowthState, HydratedState, and Fertilizer states.
 */

#include <gtest/gtest.h>
#include "Plant.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "SeedState.h"
#include "GerminationState.h"
#include "SaplingState.h"
#include "MatureState.h"
#include "DeadState.h"
#include "HydratedState.h"
#include "NotHydratedState.h"
#include "FertilizedState.h"
#include "NonFertilizerState.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class StatePatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    Plant* plant;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        plant = factory->createPlant();
    }
    
    void TearDown() override {
        delete plant;
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

// Plant Growth State Tests
TEST_F(StatePatternTest, PlantStartsInSeedState) {
    EXPECT_EQ(plant->getMaturityState(), "Seed");
}

TEST_F(StatePatternTest, PlantTransitionsFromSeedToGermination) {
    plant->setMaturityState(new SeedState());
    EXPECT_EQ(plant->getMaturityState(), "Seed");
    
    plant->grow();
    EXPECT_EQ(plant->getMaturityState(), "Germination");
}

TEST_F(StatePatternTest, PlantGrowthProgression) {
    plant->setMaturityState(new SeedState());
    
    plant->grow(); // Seed -> Germination
    EXPECT_EQ(plant->getMaturityState(), "Germination");
    
    plant->grow(); // Germination -> Sapling
    EXPECT_EQ(plant->getMaturityState(), "Sapling");
    
    plant->grow(); // Sapling -> Mature
    EXPECT_EQ(plant->getMaturityState(), "Mature");
}

TEST_F(StatePatternTest, MaturePlantStaysMature) {
    plant->setMaturityState(new MatureState());
    EXPECT_EQ(plant->getMaturityState(), "Mature");
    
    plant->grow();
    EXPECT_EQ(plant->getMaturityState(), "Mature") << "Mature plant should remain mature";
}

TEST_F(StatePatternTest, PlantCanTransitionToDead) {
    plant->setMaturityState(new DeadState());
    EXPECT_EQ(plant->getMaturityState(), "Dead");
}

// Hydration State Tests
TEST_F(StatePatternTest, PlantStartsNotHydrated) {
    Water* waterState = plant->getWaterState();
    ASSERT_NE(waterState, nullptr);
    
    NotHydratedState* notHydrated = dynamic_cast<NotHydratedState*>(waterState);
    EXPECT_NE(notHydrated, nullptr) << "Plant should start in NotHydrated state";
}

TEST_F(StatePatternTest, PlantCanBeWatered) {
    plant->setWaterState(new NotHydratedState());
    
    plant->water();
    
    Water* waterState = plant->getWaterState();
    HydratedState* hydrated = dynamic_cast<HydratedState*>(waterState);
    EXPECT_NE(hydrated, nullptr) << "Plant should be hydrated after watering";
}

TEST_F(StatePatternTest, HydratedPlantCanBecomeDehydrated) {
    plant->setWaterState(new HydratedState());
    
    plant->dehydrate();
    
    Water* waterState = plant->getWaterState();
    NotHydratedState* notHydrated = dynamic_cast<NotHydratedState*>(waterState);
    EXPECT_NE(notHydrated, nullptr) << "Plant should be dehydrated";
}

// Fertilizer State Tests
TEST_F(StatePatternTest, PlantStartsNonFertilized) {
    Fertilizer* fertState = plant->getFertilizerState();
    ASSERT_NE(fertState, nullptr);
    
    NonFertilizerState* nonFert = dynamic_cast<NonFertilizerState*>(fertState);
    EXPECT_NE(nonFert, nullptr) << "Plant should start in NonFertilized state";
}

TEST_F(StatePatternTest, PlantCanBeFertilized) {
    plant->setFertilizerState(new NonFertilizerState());
    
    plant->fertilize();
    
    Fertilizer* fertState = plant->getFertilizerState();
    FertilizedState* fertilized = dynamic_cast<FertilizedState*>(fertState);
    EXPECT_NE(fertilized, nullptr) << "Plant should be fertilized";
}

TEST_F(StatePatternTest, FertilizedPlantCanLoseFertilizer) {
    plant->setFertilizerState(new FertilizedState());
    
    plant->removeFertilizer();
    
    Fertilizer* fertState = plant->getFertilizerState();
    NonFertilizerState* nonFert = dynamic_cast<NonFertilizerState*>(fertState);
    EXPECT_NE(nonFert, nullptr) << "Plant should lose fertilizer state";
}

TEST_F(StatePatternTest, StateTransitionsAreIndependent) {
    // Test that growth, water, and fertilizer states are independent
    plant->setMaturityState(new SeedState());
    plant->setWaterState(new NotHydratedState());
    plant->setFertilizerState(new NonFertilizerState());
    
    // Change one state
    plant->grow();
    EXPECT_EQ(plant->getMaturityState(), "Germination");
    
    // Other states should remain unchanged
    NotHydratedState* notHydrated = dynamic_cast<NotHydratedState*>(plant->getWaterState());
    NonFertilizerState* nonFert = dynamic_cast<NonFertilizerState*>(plant->getFertilizerState());
    
    EXPECT_NE(notHydrated, nullptr) << "Water state should remain NotHydrated";
    EXPECT_NE(nonFert, nullptr) << "Fertilizer state should remain NonFertilized";
}
