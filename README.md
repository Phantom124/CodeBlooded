# CodeBlooded

PLANT NURSERY SIMULATOR
## Overview
Welcome to DeBUG Nursery, a C++ project inspired the vibrant energy of spring in South Africa.
This simulator models the day-to-day operations of a thriving nursery, where plants grow, customers shop, and staff keep everything running smoothly.

## Features:
### Greenhouse
- Manage and monitor various plant types.
- Track plant growth stages.
- Simulate real-time plant updates.
- Maintains a dynamic inventory of all plants.

### Staff System
- Staff can add, delete, and monitor plants in the greenhouse.
- Greenhouse conditions are managed automatically.
- Staff interactions are protected.

### Customer Interactions
- Customer can browse and view plants.
- Access is secured via control rights.


## Installation Instructions:  
## Plant Nursery GUI - Build and Run Instructions

### Prerequisites

Before building the project, ensure you have the following installed:

- *Qt 5.15 or higher* (with QtWidgets module)
- *C++17 compatible compiler* (g++, clang++, or MSVC)
- *qmake* (comes with Qt installation)

### Installing Qt on Ubuntu/Debian

bash
sudo apt-get update
sudo apt-get install qt5-default qtbase5-dev qtcreator


### Installing Qt on Other Platforms

- *Windows/macOS*: Download Qt from [qt.io/download](https://www.qt.io/download)
- Select Qt 5.15 or later during installation
- Make sure QtWidgets module is included

## Building the Project

### Quick Start (Using build script)

bash
# Navigate to project directory
cd CodeBlooded

# Make build script executable (first time only)
chmod +x build.sh

# Build and run
bash build.sh


### Manual Build

bash
# Navigate to project directory
cd CodeBlooded

# Generate Makefile from Qt project file
qmake app.pro

# Compile the project
make

# Run the application
./bin/PlantNurseryGUI


### Clean Build (if you encounter issues)

bash
# Remove all build artifacts
make clean
rm -rf build/ bin/ Makefile .qmake.stash

# Rebuild from scratch
qmake app.pro
make

# Run
./bin/PlantNurseryGUI


## Running the Application

After successful build, the executable will be located at:

./bin/PlantNurseryGUI


Run it directly:
bash
./bin/PlantNurseryGUI


## Login Credentials

### Staff Portal
- Username: admin
- Password: admin

### Customer Portal
- No credentials required (click "Customer" and login)

## Troubleshooting

### Qt not found
*Error*: qmake: command not found

*Solution*: 
bash
# Ubuntu/Debian
sudo apt-get install qt5-qmake

# Or add Qt to PATH if installed manually
export PATH=/path/to/Qt/5.15.x/gcc_64/bin:$PATH


### Missing Qt5Widgets
*Error*: cannot find -lQt5Widgets

*Solution*:
bash
sudo apt-get install qtbase5-dev


### Build fails with compiler errors
*Error*: Various C++ compilation errors

*Solution*:
bash
# Ensure you have a C++17 compatible compiler
g++ --version  # Should be 7.0 or higher

# Update if needed
sudo apt-get install g++


### Permission denied on build.sh
*Error*: Permission denied: ./build.sh

*Solution*:
bash
chmod +x build.sh


## Using Qt Creator (Alternative)

If you prefer using Qt Creator IDE:

1. Open Qt Creator
2. Go to *File → Open File or Project*
3. Navigate to and select app.pro
4. Configure the project with your installed Qt kit
5. Click the *Build* button (hammer icon)
6. Click the *Run* button (play icon)

## Project Structure


CodeBlooded/
├── app.pro                 # Qt project configuration
├── build.sh                # Build script
├── main.cpp                # Application entry point
├── styles.qss              # Application stylesheet
├── resources.qrc           # Qt resource definitions
├── Common/                 # Shared UI components
│   └── LoginDialog.*
├── CustomerWindows/        # Customer interface
│   ├── CustomerMainWindow.*
│   ├── ReturnOrderDialog.*
│   └── ReceiptDialog.*
├── StaffWindows/           # Staff interface
│   ├── StaffMainWindow.*
│   ├── PlantManagementWidget.*
│   └── StaffManagementWidget.*
├── resources/              # Application resources
│   └── fonts/
│       └── PressStart2P.ttf
└── [Backend implementation files...]


## Features

### Customer Interface
- Browse and filter plant inventory by type and maturity
- Add decorations to plants (Red Pot, Ribbon, Scent, Gift Wrap)
- Shopping cart with automatic/manual discount codes
- Secure checkout with receipt generation
- Return orders using receipt ID

### Staff Interface
- Add and remove plants from inventory
- Monitor plant health and growth stages
- Process maintenance commands (water, fertilizer)
- Manage handler chain for command processing
- Simulate time passage for plant growth

## Documentation:
[Report] --> https://docs.google.com/document/d/1Ymhf6FpDXvqxfgE9jXweNniZir6k7LTdTUMqpMDIdqU/edit?tab=t.0
[Presentation]  --> https://www.canva.com/design/DAG3rZu78LI/Uu_vM_KPNC5LIasdJAAahw/edit

## MEET THE TEAM
Jared Williams - U24581039

Zaman Bassa - U24744931

Obed Edom Mbaya - U24595889 

Ange Yehouessi - U24614484

Joshua Mahabeer - U24597092
