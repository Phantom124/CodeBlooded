# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g -O0

# Target executable
TARGET = plant_sim

# Source files
SOURCES = main.cpp \
          Plant.cpp \
          Cactus.cpp \
          Rose.cpp \
          Sunflower.cpp \
          SeedState.cpp \
          GerminationState.cpp \
          SaplingState.cpp \
          MatureState.cpp \
          DeadState.cpp \
          HydratedState.cpp \
          NotHydratedState.cpp \
          FertilizedState.cpp \
          NonFertilizerState.cpp \
          Water.cpp \
          PlantMonitor.cpp \
          DeadMonitor.cpp \
          FertilizerMonitor.cpp \
          WaterMonitor.cpp \
          Command.cpp \
          PlantCommand.cpp \
          DeadCommand.cpp \
          WaterCommand.cpp \
          FertilizerCommand.cpp \
          PlantGroup.cpp \
          StaffSystem.cpp \
          StaffHandler.cpp \
          WaterHandler.cpp \
          FertilizerHandler.cpp \
          DeadHandler.cpp \
          QueueIterator.cpp \
          PlantFactory.cpp \
          RoseFactory.cpp \
          CactusFactory.cpp \
          SunflowerFactory.cpp \
          PlantDecorator.cpp \
          Ribbon.cpp \
          RedPot.cpp \
          Scent.cpp \
          QueryBuilder.cpp\
          QueryProduct.cpp\
          ProxyGreenHouseInventory.cpp\
          RealGreenHouseInventory.cpp \
          GreenHouseInventory.cpp\

# Object files (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Memory leak check (macOS)
checkleaks: $(TARGET)
	MallocStackLogging=1 leaks --atExit -- ./$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all run clean checkleaks
