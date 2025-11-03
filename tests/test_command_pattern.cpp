/**/**

 * @file test_command_pattern.cpp * @file test_command_pattern.cpp

 * @brief Unit tests for Command Pattern implementation * @brief Unit tests for Command pattern implementation

 *  * 

 * Tests the command system for plant operations (Water, Fertilizer, Dead, GetPlant). * Tests the command system for plant operations (Water, Fertilizer, etc.).

 */ */



#include <gtest/gtest.h>#include <gtest/gtest.h>

#include "WaterCommand.h"#include "WaterCommand.h"

#include "FertilizerCommand.h"#include "FertilizerCommand.h"

#include "DeadCommand.h"#include "DeadCommand.h"

#include "GetPlantCommand.h"#include "GetPlantCommand.h"

#include "CustomerCommand.h"#include "Rose.h"

#include "Rose.h"#include "RoseFactory.h"

#include "RoseFactory.h"#include "WaterMonitor.h"

#include "WaterMonitor.h"#include "FertilizerMonitor.h"

#include "FertilizerMonitor.h"#include "DeadMonitor.h"

#include "DeadMonitor.h"

#include "QueryBuilder.h"class CommandPatternTest : public ::testing::Test {

protected:

class CommandPatternTest : public ::testing::Test {    WaterMonitor* waterMonitor;

protected:    FertilizerMonitor* fertilizerMonitor;

    WaterMonitor* waterMonitor;    DeadMonitor* deadMonitor;

    FertilizerMonitor* fertilizerMonitor;    RoseFactory* factory;

    DeadMonitor* deadMonitor;    Plant* plant;

    QueryBuilder* queryBuilder;    

    RoseFactory* factory;    void SetUp() override {

    Plant* plant;        waterMonitor = new WaterMonitor();

            fertilizerMonitor = new FertilizerMonitor();

    void SetUp() override {        deadMonitor = new DeadMonitor();

        waterMonitor = new WaterMonitor();        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);

        fertilizerMonitor = new FertilizerMonitor();        plant = factory->createPlant();

        deadMonitor = new DeadMonitor();    }

        queryBuilder = new QueryBuilder();    

        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);    void TearDown() override {

        plant = factory->createPlant();        delete plant;

    }        delete factory;

            delete waterMonitor;

    void TearDown() override {        delete fertilizerMonitor;

        delete plant;        delete deadMonitor;

        delete factory;    }

        delete waterMonitor;};

        delete fertilizerMonitor;

        delete deadMonitor;TEST_F(CommandPatternTest, WaterCommandCreatesSuccessfully) {


    }    ASSERT_NE(cmd, nullptr);

};    EXPECT_EQ(cmd->getType(), WATER);

    delete cmd;

TEST_F(CommandPatternTest, WaterCommandCreatesSuccessfully) {}

    WaterCommand* cmd = new WaterCommand(plant);

    ASSERT_NE(cmd, nullptr);TEST_F(CommandPatternTest, FertilizerCommandCreatesSuccessfully) {

    EXPECT_EQ(cmd->getType(), WATER);    FertilizerCommand* cmd = new FertilizerCommand(plant);

    delete cmd;    ASSERT_NE(cmd, nullptr);

}    EXPECT_EQ(cmd->getType(), FERTILIZER);

    delete cmd;

TEST_F(CommandPatternTest, FertilizerCommandCreatesSuccessfully) {}

    FertilizerCommand* cmd = new FertilizerCommand(plant);

    ASSERT_NE(cmd, nullptr);TEST_F(CommandPatternTest, DeadCommandCreatesSuccessfully) {

    EXPECT_EQ(cmd->getType(), FERTILIZER);    DeadCommand* cmd = new DeadCommand(plant);

    delete cmd;    ASSERT_NE(cmd, nullptr);

}    EXPECT_EQ(cmd->getType(), DEAD);

    delete cmd;

TEST_F(CommandPatternTest, DeadCommandCreatesSuccessfully) {}

    DeadCommand* cmd = new DeadCommand(plant);

    ASSERT_NE(cmd, nullptr);TEST_F(CommandPatternTest, CommandHasValidPlant) {

    EXPECT_EQ(cmd->getType(), DEAD);    WaterCommand* cmd = new WaterCommand(plant);

    delete cmd;    ASSERT_NE(cmd, nullptr);

}    EXPECT_NE(cmd->getPlant(), nullptr);

    delete cmd;

TEST_F(CommandPatternTest, GetPlantCommandCreatesSuccessfully) {}

    GetPlantCommand* cmd = new GetPlantCommand(plant);

    ASSERT_NE(cmd, nullptr);TEST_F(CommandPatternTest, DifferentCommandsHaveDifferentTypes) {

    EXPECT_EQ(cmd->getType(), GETPLANT);    WaterCommand* waterCmd = new WaterCommand(plant);

    delete cmd;    FertilizerCommand* fertCmd = new FertilizerCommand(plant);

}    

    EXPECT_NE(waterCmd->getType(), fertCmd->getType());

TEST_F(CommandPatternTest, WaterCommandReturnsCorrectPlant) {    

    WaterCommand* cmd = new WaterCommand(plant);    delete waterCmd;

    EXPECT_EQ(cmd->getPlant(), plant);    delete fertCmd;

    delete cmd;}

}

TEST_F(CommandPatternTest, FertilizerCommandReturnsCorrectPlant) {
    FertilizerCommand* cmd = new FertilizerCommand(plant);
    EXPECT_EQ(cmd->getPlant(), plant);
    delete cmd;
}

TEST_F(CommandPatternTest, DeadCommandReturnsCorrectPlant) {
    DeadCommand* cmd = new DeadCommand(plant);
    EXPECT_EQ(cmd->getPlant(), plant);
    delete cmd;
}

TEST_F(CommandPatternTest, GetPlantCommandReturnsCorrectPlant) {
    GetPlantCommand* cmd = new GetPlantCommand(plant);
    EXPECT_EQ(cmd->getPlant(), plant);
    delete cmd;
}

TEST_F(CommandPatternTest, CommandsHaveDistinctTypes) {
    WaterCommand* waterCmd = new WaterCommand(plant);
    FertilizerCommand* fertCmd = new FertilizerCommand(plant);
    DeadCommand* deadCmd = new DeadCommand(plant);
    GetPlantCommand* getCmd = new GetPlantCommand(plant);
    
    EXPECT_NE(waterCmd->getType(), fertCmd->getType());
    EXPECT_NE(waterCmd->getType(), deadCmd->getType());
    EXPECT_NE(waterCmd->getType(), getCmd->getType());
    EXPECT_NE(fertCmd->getType(), deadCmd->getType());
    EXPECT_NE(fertCmd->getType(), getCmd->getType());
    EXPECT_NE(deadCmd->getType(), getCmd->getType());
    
    delete waterCmd;
    delete fertCmd;
    delete deadCmd;
    delete getCmd;
}

TEST_F(CommandPatternTest, CustomerCommandCreatesSuccessfully) {
    Plant* plants[] = {plant};
    CustomerCommand* cmd = new CustomerCommand(plants, 1);
    ASSERT_NE(cmd, nullptr);
    delete cmd;
}

TEST_F(CommandPatternTest, CustomerCommandHandlesMultiplePlants) {
    Plant* plant2 = factory->createPlant();
    Plant* plant3 = factory->createPlant();
    Plant* plants[] = {plant, plant2, plant3};
    
    CustomerCommand* cmd = new CustomerCommand(plants, 3);
    ASSERT_NE(cmd, nullptr);
    
    delete cmd;
    delete plant2;
    delete plant3;
}
