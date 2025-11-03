# GoogleTest Testing Suite - Plant Nursery System

## Overview
Comprehensive unit testing suite for all design patterns implemented in the Plant Nursery project (excluding GUI components).

## Design Patterns Tested

### ✅ 1. Factory Pattern
- **File:** `test_factory_pattern.cpp`
- **Tests:** RoseFactory, CactusFactory, SunflowerFactory
- **Coverage:** Plant creation, factory polymorphism, monitor attachment

### ✅ 2. State Pattern
- **File:** `test_state_pattern.cpp`
- **Tests:** PlantGrowthState, HydratedState, FertilizedState
- **Coverage:** State transitions, independent state management, growth progression

### ✅ 3. Decorator Pattern
- **File:** `test_decorator_pattern.cpp`
- **Tests:** GiftWrap, RedPot, Ribbon, Scent
- **Coverage:** Price calculation, decoration stacking, description modification

### ✅ 4. Command Pattern
- **File:** `test_command_pattern.cpp`
- **Tests:** WaterCommand, FertilizerCommand, DeadCommand, GetPlantCommand, CustomerCommand
- **Coverage:** Command creation, type differentiation, plant association

### ✅ 5. Chain of Responsibility
- **File:** `test_chain_of_responsibility.cpp`
- **Tests:** StaffHandler, WaterHandler, FertilizerHandler, DeadHandler, SalesHandler
- **Coverage:** Chain linking, request handling, command delegation

### ✅ 6. Memento Pattern
- **File:** `test_memento_pattern.cpp`
- **Tests:** OrderMemento, Caretaker
- **Coverage:** State capture, restoration, order history management

### ✅ 7. Iterator Pattern
- **File:** `test_iterator_pattern.cpp`
- **Tests:** QueueIterator, StaffSystem
- **Coverage:** Traversal, multiple iterators, empty collection handling

### ✅ 8. Facade Pattern
- **File:** `test_facade_pattern.cpp`
- **Tests:** CustomerFacade, GreenHouseFacade
- **Coverage:** Simplified interfaces, singleton implementation, subsystem hiding

### ✅ 9. Proxy Pattern
- **File:** `test_proxy_pattern.cpp`
- **Tests:** ProxyGreenHouseInventory, RealGreenHouseInventory
- **Coverage:** Access control, delegation, protection proxy

### ✅ 10. Strategy Pattern
- **File:** `test_strategy_pattern.cpp`
- **Tests:** NormalPrice, BulkDiscount, Save10Discount
- **Coverage:** Price calculation algorithms, strategy swapping, discount application

### ✅ 11. Composite Pattern
- **File:** `test_composite_pattern.cpp`
- **Tests:** PlantComponent, Plant, PlantGroup
- **Coverage:** Tree structure, uniform treatment, price aggregation

### ✅ 12. Builder Pattern
- **File:** `test_builder_pattern.cpp`
- **Tests:** QueryBuilder, SelectQueryBuilder, InsertQueryBuilder, DeleteQueryBuilder
- **Coverage:** Incremental construction, query building, separation of concerns

## Running Tests

### Quick Start
```bash
cd tests
./build_and_run_tests.sh
```

### Manual Build
```bash
cd tests
mkdir -p build
cd build
cmake ..
cmake --build .
./plant_nursery_tests
```

### Run Specific Pattern Tests
```bash
cd tests/build

# Factory Pattern
./plant_nursery_tests --gtest_filter=FactoryPatternTest.*

# State Pattern
./plant_nursery_tests --gtest_filter=StatePatternTest.*

# Decorator Pattern
./plant_nursery_tests --gtest_filter=DecoratorPatternTest.*

# Command Pattern
./plant_nursery_tests --gtest_filter=CommandPatternTest.*

# Chain of Responsibility
./plant_nursery_tests --gtest_filter=ChainOfResponsibilityTest.*

# Memento Pattern
./plant_nursery_tests --gtest_filter=MementoPatternTest.*

# Iterator Pattern
./plant_nursery_tests --gtest_filter=IteratorPatternTest.*

# Facade Pattern
./plant_nursery_tests --gtest_filter=FacadePatternTest.*

# Proxy Pattern
./plant_nursery_tests --gtest_filter=ProxyPatternTest.*

# Strategy Pattern
./plant_nursery_tests --gtest_filter=StrategyPatternTest.*

# Composite Pattern
./plant_nursery_tests --gtest_filter=CompositePatternTest.*

# Builder Pattern
./plant_nursery_tests --gtest_filter=BuilderPatternTest.*
```

### List All Tests
```bash
cd tests/build
./plant_nursery_tests --gtest_list_tests
```

### Verbose Output
```bash
cd tests/build
./plant_nursery_tests --gtest_verbose
```

## Test Structure

```
tests/
├── CMakeLists.txt                      # Build configuration
├── build_and_run_tests.sh             # Automated build & run script
├── test_main.cpp                       # Test runner entry point
├── test_globals.cpp                    # Global stubs (for Qt dependencies)
├── test_factory_pattern.cpp            # Factory Pattern tests
├── test_state_pattern.cpp              # State Pattern tests
├── test_decorator_pattern.cpp          # Decorator Pattern tests
├── test_command_pattern.cpp            # Command Pattern tests
├── test_chain_of_responsibility.cpp    # Chain of Responsibility tests
├── test_memento_pattern.cpp            # Memento Pattern tests
├── test_iterator_pattern.cpp           # Iterator Pattern tests
├── test_facade_pattern.cpp             # Facade Pattern tests
├── test_proxy_pattern.cpp              # Proxy Pattern tests
├── test_strategy_pattern.cpp           # Strategy Pattern tests
├── test_composite_pattern.cpp          # Composite Pattern tests
├── test_builder_pattern.cpp            # Builder Pattern tests
└── README.md                           # This file
```

## Test Statistics

- **Total Test Files:** 12 (one per design pattern)
- **Total Design Patterns:** 12
- **Estimated Test Cases:** 150+
- **GUI Components:** Excluded (as requested)

## Adding New Tests

1. Create a new test file: `test_<pattern_name>.cpp`
2. Add it to `TEST_SOURCES` in `CMakeLists.txt`
3. Include necessary headers
4. Create test fixture class inheriting from `::testing::Test`
5. Write tests using GoogleTest macros

### Test Template
```cpp
#include <gtest/gtest.h>
#include "YourClass.h"

class YourPatternTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize test objects
    }
    
    void TearDown() override {
        // Clean up
    }
};

TEST_F(YourPatternTest, TestName) {
    // Arrange
    // Act
    // Assert
    EXPECT_TRUE(condition);
}
```

## GoogleTest Assertions Reference

```cpp
// Basic assertions
EXPECT_TRUE(condition);
EXPECT_FALSE(condition);
EXPECT_EQ(expected, actual);      // ==
EXPECT_NE(val1, val2);            // !=
EXPECT_LT(val1, val2);            // <
EXPECT_GT(val1, val2);            // >
EXPECT_LE(val1, val2);            // <=
EXPECT_GE(val1, val2);            // >=

// Pointer assertions
EXPECT_NE(pointer, nullptr);
EXPECT_EQ(pointer, nullptr);

// Floating point
EXPECT_DOUBLE_EQ(expected, actual);
EXPECT_FLOAT_EQ(expected, actual);

// String assertions
EXPECT_STREQ(str1, str2);
EXPECT_STRCASEEQ(str1, str2);

// Exception assertions
EXPECT_THROW(statement, exception_type);
EXPECT_NO_THROW(statement);
```

## Requirements

- CMake 3.14 or higher
- C++17 compiler
- Internet connection (first build only, to download GoogleTest)

## Troubleshooting

### Build Fails
```bash
# Clean and rebuild
cd tests
rm -rf build
./build_and_run_tests.sh
```

### Missing Dependencies
```bash
# Install CMake and build tools
sudo apt-get update
sudo apt-get install cmake build-essential
```

### Linker Errors
- Check that all source files are listed in `BACKEND_SOURCES` in CMakeLists.txt
- Ensure no GUI-dependent code is being linked

## Notes

- GUI components (Qt windows, dialogs, etc.) are intentionally excluded
- Tests focus on core business logic and design patterns
- Each test file is independent and can be run separately
- All tests clean up their resources in TearDown()

## Contributing

When adding new tests:
1. Follow the existing naming convention
2. Include comprehensive documentation
3. Test both success and failure cases
4. Clean up all allocated memory
5. Use meaningful test names that describe what is being tested

## Contact

For issues or questions about the test suite, contact the development team.
