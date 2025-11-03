/**
 * @file test_chain_of_responsibility.cpp
 * @brief Unit tests for Chain of Responsibility Pattern
 * 
 * Tests the StaffHandler chain (WaterHandler, FertilizerHandler, DeadHandler, SalesHandler).
 */

#include <gtest/gtest.h>
#include "StaffHandler.h"
#include "WaterHandler.h"
#include "FertilizerHandler.h"
#include "DeadHandler.h"
#include "SalesHandler.h"
#include "StaffSystem.h"
#include "WaterCommand.h"
#include "FertilizerCommand.h"
#include "DeadCommand.h"
#include "GetPlantCommand.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class ChainOfResponsibilityTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    Plant* plant;
    
    WaterHandler* waterHandler;
    FertilizerHandler* fertilizerHandler;
    DeadHandler* deadHandler;
    SalesHandler* salesHandler;
    StaffSystem* staffSystem;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        plant = factory->createPlant();
        
        // Create handlers
        waterHandler = new WaterHandler();
        fertilizerHandler = new FertilizerHandler();
        deadHandler = new DeadHandler();
        salesHandler = new SalesHandler();
        
        // Set up chain
        waterHandler->setSuccessor(fertilizerHandler);
        fertilizerHandler->setSuccessor(deadHandler);
        deadHandler->setSuccessor(salesHandler);
        
        // Set query builders
        waterHandler->setQueryBuilder(queryBuilder);
        fertilizerHandler->setQueryBuilder(queryBuilder);
        deadHandler->setQueryBuilder(queryBuilder);
        salesHandler->setQueryBuilder(queryBuilder);
        
        staffSystem = new StaffSystem();
    }
    
    void TearDown() override {
        delete staffSystem;
        delete waterHandler;
        delete fertilizerHandler;
        delete deadHandler;
        delete salesHandler;
        delete plant;
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(ChainOfResponsibilityTest, WaterHandlerCreatesSuccessfully) {
    ASSERT_NE(waterHandler, nullptr);
    EXPECT_NE(waterHandler->getSuccessor(), nullptr);
}

TEST_F(ChainOfResponsibilityTest, ChainIsProperlyLinked) {
    EXPECT_EQ(waterHandler->getSuccessor(), fertilizerHandler);
    EXPECT_EQ(fertilizerHandler->getSuccessor(), deadHandler);
    EXPECT_EQ(deadHandler->getSuccessor(), salesHandler);
}

TEST_F(ChainOfResponsibilityTest, WaterHandlerHandlesWaterCommand) {
    WaterCommand* cmd = new WaterCommand(plant);
    
    // Should not throw
    EXPECT_NO_THROW(waterHandler->handleRequest(cmd, staffSystem));
    
    delete cmd;
}

TEST_F(ChainOfResponsibilityTest, FertilizerHandlerHandlesFertilizerCommand) {
    FertilizerCommand* cmd = new FertilizerCommand(plant);
    
    // Should not throw
    EXPECT_NO_THROW(fertilizerHandler->handleRequest(cmd, staffSystem));
    
    delete cmd;
}

TEST_F(ChainOfResponsibilityTest, DeadHandlerHandlesDeadCommand) {
    DeadCommand* cmd = new DeadCommand(plant);
    
    // Should not throw
    EXPECT_NO_THROW(deadHandler->handleRequest(cmd, staffSystem));
    
    delete cmd;
}

TEST_F(ChainOfResponsibilityTest, SalesHandlerHandlesGetPlantCommand) {
    GetPlantCommand* cmd = new GetPlantCommand(plant);
    
    // Should not throw
    EXPECT_NO_THROW(salesHandler->handleRequest(cmd, staffSystem));
    
    delete cmd;
}

TEST_F(ChainOfResponsibilityTest, CommandPassesThroughChain) {
    // Water command should be handled by water handler
    WaterCommand* waterCmd = new WaterCommand(plant);
    EXPECT_NO_THROW(waterHandler->handleRequest(waterCmd, staffSystem));
    
    // Fertilizer command should pass through water handler to fertilizer handler
    FertilizerCommand* fertCmd = new FertilizerCommand(plant);
    EXPECT_NO_THROW(waterHandler->handleRequest(fertCmd, staffSystem));
    
    // Dead command should pass through to dead handler
    DeadCommand* deadCmd = new DeadCommand(plant);
    EXPECT_NO_THROW(waterHandler->handleRequest(deadCmd, staffSystem));
    
    // GetPlant command should pass through to sales handler
    GetPlantCommand* getCmd = new GetPlantCommand(plant);
    EXPECT_NO_THROW(waterHandler->handleRequest(getCmd, staffSystem));
    
    delete waterCmd;
    delete fertCmd;
    delete deadCmd;
    delete getCmd;
}

TEST_F(ChainOfResponsibilityTest, HandlersCanBeResetToAvailable) {
    waterHandler->resetAvailable();
    fertilizerHandler->resetAvailable();
    deadHandler->resetAvailable();
    salesHandler->resetAvailable();
    
    // Should not throw after reset
    WaterCommand* cmd = new WaterCommand(plant);
    EXPECT_NO_THROW(waterHandler->handleRequest(cmd, staffSystem));
    delete cmd;
}

TEST_F(ChainOfResponsibilityTest, HandlersCanCreateQueries) {
    QueryProduct* selectQuery = waterHandler->createSelectQuery(plant);
    EXPECT_NE(selectQuery, nullptr);
    delete selectQuery;
    
    QueryProduct* insertQuery = fertilizerHandler->createInsertQuery(plant);
    EXPECT_NE(insertQuery, nullptr);
    delete insertQuery;
    
    QueryProduct* deleteQuery = deadHandler->createDeleteQuery(plant);
    EXPECT_NE(deleteQuery, nullptr);
    delete deleteQuery;
}
