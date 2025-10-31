# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g -O0

# Target executable
TARGET = plant_sim

# Source files
SOURCES = Builder_Proxy.cpp \
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
          QueryProduct.cpp \
          QueryBuilder.cpp\
          ProxyGreenHouseInventory.cpp\
          GreenHouseInventory.cpp\
          RealGreenHouseInventory.cpp\
          SelectQueryBuilder.cpp\
          InsertQueryBuilder.cpp\
          DeleteQueryBuilder.cpp\
          Customer.cpp\
          

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

# Memory leak check (macOS or fallback to Valgrind)
checkleaks: $(TARGET)
	@if command -v leaks >/dev/null 2>&1 ; then \
	  MallocStackLogging=1 leaks --atExit -- ./$(TARGET); \
	else \
	  echo "leaks not found; running valgrind --leak-check=full ./$(TARGET)"; \
	  valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET); \
	fi

# Valgrind target (explicit)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all run clean checkleaks
