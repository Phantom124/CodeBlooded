# 🌱 CodeBlooded: Plant Nursery Simulator

Welcome to **DeBUG Nursery**, a C++ and Qt-based project inspired by the vibrant energy of spring in South Africa.  
This simulator models the day-to-day operations of a thriving nursery — where plants grow, customers shop, and staff keep everything running smoothly.

---

## 🌼 Overview

The **Plant Nursery Simulator** lets you experience both sides of nursery life:
- As a **Customer**, explore, decorate, and purchase plants.
- As **Staff**, maintain and manage plant growth in a digital greenhouse.

---

## 🌿 Features

### 🏡 Greenhouse
- Manage and monitor multiple plant types.  
- Track plant growth stages dynamically.  
- Simulate real-time growth updates.  
- Maintain a synchronized plant inventory.

### 👩‍🌾 Staff System
- Add, delete, and monitor plants.  
- Manage greenhouse conditions automatically.  
- Protected access via control rights.

### 👨‍👩‍🌾 Customer Interactions
- Browse and view available plants.  
- Add decorations like ribbons or pots.  
- Purchase plants securely.  
- View receipts and manage returns.

---

## ⚙️ Installation Instructions

### 🧰 Prerequisites

Ensure you have the following installed before building:

- **Qt 5.15 or higher** (with QtWidgets module)
- **C++17-compatible compiler** (g++, clang++, or MSVC)
- **qmake** (included with Qt)

---

### 🪟 Installing Qt

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install qt5-default qtbase5-dev qtcreator


🧩 Building the Project
🏃 Quick Start (Using build script)
# Navigate to project directory
cd CodeBlooded

# Make build script executable (first time only)
chmod +x build.sh

# Build and run
bash build.sh

🧱 Manual Build
cd CodeBlooded
qmake app.pro
make
./bin/PlantNurseryGUI

🧹 Clean Build
make clean
rm -rf build/ bin/ Makefile .qmake.stash
qmake app.pro
make
./bin/PlantNurseryGUI

🚀 Running the Application
./bin/PlantNurseryGUI


🔐 Login Credentials
👷 Staff Portal

Username: admin

Password: admin

🛒 Customer Portal
  
No credentials required — simply click “Customer” and login.

🗂️ Project Structure
CodeBlooded/
├── app.pro                 # Qt project configuration
├── build.sh                # Build script
├── main.cpp                # Application entry point
├── styles.qss              # Application stylesheet
├── resources.qrc           # Qt resource definitions
├── Common/
│   └── LoginDialog.*
├── CustomerWindows/
│   ├── CustomerMainWindow.*
│   ├── ReturnOrderDialog.*
│   └── ReceiptDialog.*
├── StaffWindows/
│   ├── StaffMainWindow.*
│   ├── PlantManagementWidget.*
│   └── StaffManagementWidget.*
├── resources/
│   └── fonts/
│       └── PressStart2P.ttf
└── [Backend implementation files...]


👥 Meet the Team
Name	Student Number
Jared Williams	U24581039
Zaman Bassa	U24744931
Obed Edom Mbaya	U24595889
Ange Yehouessi	U24614484
Joshua Mahabeer	U24597092