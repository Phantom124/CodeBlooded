#!/bin/bash

# Plant Nursery GUI Build Script
# This script builds the Qt GUI application

echo "================================"
echo "Plant Nursery GUI Build Script"
echo "================================"
echo ""

# Check if qmake is available
if ! command -v qmake &> /dev/null
then
    echo "ERROR: qmake not found!"
    echo "Please install Qt development packages."
    echo "On Ubuntu/Debian: sudo apt-get install qt5-default"
    exit 1
fi

echo "Qt version:"
qmake --version
echo ""

# Clean previous build
echo "Cleaning previous build..."
make clean 2>/dev/null
rm -rf build/ bin/ Makefile .qmake.stash 2>/dev/null
echo "Clean complete."
echo ""

# Generate Makefile
echo "Generating Makefile with qmake..."
qmake app.pro

if [ $? -ne 0 ]; then
    echo "ERROR: qmake failed!"
    exit 1
fi
echo "Makefile generated successfully."
echo ""

# Build the project
echo "Building project..."
make -j$(nproc)

if [ $? -ne 0 ]; then
    echo ""
    echo "================================"
    echo "BUILD FAILED!"
    echo "================================"
    echo ""
    echo "Please check the error messages above."
    echo "Common issues:"
    echo "  - Missing Qt development packages"
    echo "  - Missing C++ compiler"
    echo "  - Syntax errors in code"
    exit 1
fi

echo ""
echo "================================"
echo "BUILD SUCCESSFUL!"
echo "================================"
echo ""
echo "Executable location: ./bin/PlantNurseryGUI"
echo ""
echo "To run the application:"
echo "  ./bin/PlantNurseryGUI"
echo ""
echo "Default staff login credentials:"
echo "  Username: admin"
echo "  Password: admin"
echo ""
