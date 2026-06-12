# RetroFuse: C++/Qt J2ME & Symbian Desktop Emulator

RetroFuse is a high-performance desktop emulation platform for J2ME and Symbian mobile application archives, built natively using **C++17** and the **Qt6 framework**. By combining UI view tracking and execution engines inside a single runtime ecosystem, it provides native instruction interpretation loops without garbage collection or intermediate translation lags.

---

## 📁 1. Project Directory Structure

Create a root directory named `retrofuse-qt` on your machine  and layout the folders and files as follows:

```text
retrofuse-qt/
├── CMakeLists.txt              # Unified build rules for Windows and Linux
├── README.md                   # Setup guide and compilation workflows
├── src/                        # Core C++ Application Source
│   ├── main.cpp                # App entry point initializing Qt
│   ├── mainwindow.h            # Main UI controller definitions
│   └── mainwindow.cpp          # App window & keyboard logic
└── third_party/                # Engine Submodule Repository Slots
    ├── eka2l1/                 # Symbian C++ core slot
    └── freej2me/               # J2ME execution core slot

```

---

## 🎮 The QWERTY-to-T9 Mapping Layout

When playing games, your desktop system keyboard functions as a virtual mechanical keypad array mapped according to the following matrix rules:

* **W / A / S / D (or Arrow Keys)** -> Directional Navigational D-Pad
* **Z / Enter** -> Primary Select / Center Trigger Key (Button A)
* **X / Escape** -> Clear Frame / Return Navigation (Button B)
* **Q / E** -> Left Soft Key / Right Soft Key (Menu Action options)
* **Top Row 0 - 9 Keys** -> Standard Numeric T9 input matrix overrides

---

## 🛠️ Compilation & Local Setup

### 🐧 1. Linux Environment Setup (Ubuntu/Debian)

Install core developer tool chains and the required library components directly via your system package manager:

```bash
sudo apt update
sudo apt install build-essential cmake qt6-base-dev qt6-declarative-dev libsdl2-dev

```

### 🪟 2. Windows Environment Setup

1. Download and install **Visual Studio 2022 Community Edition** (Ensure **"Desktop development with C++"** workspace tracking is checked).
2. Install **CMake** and verify it is mapped onto your global Windows environment system PATH variables.
3. Fetch dependencies cleanly via **vcpkg**:
```powershell
git clone [https://github.com/microsoft/vcpkg.git](https://github.com/microsoft/vcpkg.git)
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg install qt6-base sdl2

```

---

## 🚀 Execution Pipelines

To build and launch the executable workspace binary from your command terminal shell, run the following unified compile sequence:

```bash
# Generate build workspace tracking folder
mkdir build
cd build

# Configure project make vectors via CMake
# (Windows users: Append your target -DCMAKE_TOOLCHAIN_FILE variable pointing to vcpkg script)
cmake ..

# Compile the final native application executable payload
cmake --build . --config Release

```