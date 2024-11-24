# keysz

A lightweight component for ESP-IDF that provides functionality for scanning a matrix of buttons using GPIO pins on an ESP8266 or similar microcontroller. The component handles the setup of the GPIO pins, scanning the matrix, and detecting button presses and releases.

## Prerequisites

- ESP-IDF installed.
- ESP8266/ESP32 development environment configured.

## Setup and Usage

To use the `keysz` component, follow these steps:

### 1. Add `keysz` to your project 
Ensure that your project has the following structure 

```
├── CMakeLists.txt
├── components
│   └── keysz
│       ├── CMakeLists.txt
│       ├── include
│       │   └── keysz.hpp
│       └── src
│           └── keysz.cpp
├── main
│   ├── CMakeLists.txt
│   └── main.cpp
├── README.md
├── sdkconfig
└ ...
```

### 2. Modify your root `CMakeLists.txt` 
Ensure that your root `CMakeLists.txt` includes the follwoing line 

```
set(EXTRA_COMPONENT_DIRS components)
```

### 3. Build and flash 

Build and flash normally with

```bash
idf.py build 
idf.py -p /dev/ttyUSBX flash 
```