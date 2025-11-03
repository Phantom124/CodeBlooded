#!/bin/bash

# Build and run GoogleTest unit tests for Plant Nursery project
# This script sets up the build directory, compiles tests, and runs them

set -e  # Exit on error

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"

echo "======================================"
echo "Plant Nursery - GoogleTest Suite"
echo "======================================"
echo ""

# Create build directory
if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning existing build directory..."
    rm -rf "$BUILD_DIR"
fi

echo "Creating build directory..."
mkdir -p "$BUILD_DIR"

# Configure with CMake
echo ""
echo "Configuring CMake..."
cd "$BUILD_DIR"
cmake ..

# Build the tests
echo ""
echo "Building tests..."
cmake --build .

# Run the tests
echo ""
echo "======================================"
echo "Running Tests"
echo "======================================"
echo ""
./plant_nursery_tests

# Show test results summary
echo ""
echo "======================================"
echo "Test Execution Complete"
echo "======================================"
