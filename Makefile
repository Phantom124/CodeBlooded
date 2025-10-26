# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = plant_sim

# Source files
SOURCES = StateTesting.cpp \
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
          Water.cpp

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

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all run clean