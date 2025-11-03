cmake_minimum_required(VERSION 3.14)
project(PlantNurseryTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module to download GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Include directories for the main project
include_directories(${PROJECT_SOURCE_DIR}/..)
include_directories(${PROJECT_SOURCE_DIR}/../Common)

# Collect all source files from parent directory (excluding main.cpp and GUI-dependent files)
set(BACKEND_SOURCES
    ../Cactus.cpp
    ../CactusFactory.cpp
    ../Caretaker.cpp
    ../Command.cpp
    ../Customer.cpp
    ../CustomerCommand.cpp
    ../CustomerFacade.cpp
    ../DeadCommand.cpp
    ../DeadHandler.cpp
    ../DeadMonitor.cpp
    ../DeadState.cpp
    ../DeleteQueryBuilder.cpp
    ../FertilizedState.cpp
    ../FertilizerCommand.cpp
    ../FertilizerHandler.cpp
    ../FertilizerMonitor.cpp
    ../GerminationState.cpp
    ../GetPlantCommand.cpp
    ../GiftWrap.cpp
    ../GreenHouseFacade.cpp
    ../GreenHouseInventory.cpp
    ../HydratedState.cpp
    ../InsertQueryBuilder.cpp
    ../Item.cpp
    ../MatureState.cpp
    ../NonFertilizerState.cpp
    ../NormalPrice.cpp
    ../NotHydratedState.cpp
    ../Order.cpp
    ../OrderMemento.cpp
    ../Plant.cpp
    ../PlantCommand.cpp
    ../PlantDecorator.cpp
    ../PlantFactory.cpp
    ../PlantGroup.cpp
    ../PlantMonitor.cpp
    ../PlantSnapshot.cpp
    ../ProxyGreenHouseInventory.cpp
    ../QueryBuilder.cpp
    ../QueryProduct.cpp
    ../QueueIterator.cpp
    ../RealGreenHouseInventory.cpp
    ../Receipt.cpp
    ../RedPot.cpp
    ../Ribbon.cpp
    ../Rose.cpp
    ../RoseFactory.cpp
    ../SalesHandler.cpp
    ../SaplingState.cpp
    ../Save10Discount.cpp
    ../Scent.cpp
    ../SeedState.cpp
    ../SelectQueryBuilder.cpp
    ../StaffHandler.cpp
    ../StaffSystem.cpp
    ../Sunflower.cpp
    ../SunflowerFactory.cpp
    ../Water.cpp
    ../WaterCommand.cpp
    ../WaterHandler.cpp
    ../WaterMonitor.cpp
    ../BulkDiscount.cpp
)

# Test source files
set(TEST_SOURCES
    test_main.cpp
    test_globals.cpp
    test_factory_pattern.cpp
    test_state_pattern.cpp
    test_decorator_pattern.cpp
    test_command_pattern.cpp
    test_chain_of_responsibility.cpp
    test_memento_pattern.cpp
    test_iterator_pattern.cpp
    test_facade_pattern.cpp
    test_proxy_pattern.cpp
    test_strategy_pattern.cpp
    test_composite_pattern.cpp
    test_builder_pattern.cpp
)

# Create test executable
add_executable(
    plant_nursery_tests
    ${TEST_SOURCES}
    ${BACKEND_SOURCES}
)

# Link against GoogleTest
target_link_libraries(
    plant_nursery_tests
    GTest::gtest_main
    GTest::gmock_main
)

# Discover tests for CTest
include(GoogleTest)
gtest_discover_tests(plant_nursery_tests)
