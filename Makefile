# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

# Target executable
TARGET = demotest

# Automatically find all .cpp files in the current directory
SRCS := $(wildcard *.cpp)

# Convert source files to object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
