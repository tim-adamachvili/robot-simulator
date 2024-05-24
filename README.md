# Robot Simulator

The RobotSimulator is a C++ application that simulates a toy robot moving on a square tabletop of dimensions 5x5 units. This application provides an interactive way to place the robot on the table, move it around, change its direction, and report its position.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Building the Project](#building-the-project)
- [Running the Simulator](#running-the-simulator)
- [Testing](#testing)

## Prerequisites

Before you begin, ensure you have the following installed on your system:
- C++ Compiler (g++)
- CMake (version 3.10 or higher)
- Make
- Git (for cloning Google Test)

You can install these using:
```bash
sudo apt update
sudo apt install build-essential cmake git
```

## Getting Started
### Clone the Google Test Repository

From within the project root directory, run:
```bash
git clone https://github.com/google/googletest.git lib/googletest
```

## Building the Project
To build the project, follow these steps:

### 1. Create a Build Directory
From the project root directory, create and navigate to a new build directory:

```bash
mkdir build && cd build
```

### 2. Generate Makefiles with CMake
Configure the project with CMake:

```bash
cmake ..
```
### 3. Compile the Project
Build the project using Make:

```bash
make
```

This will compile all source files and link the executable named RobotSimulator.

## Running the Simulator
To run the Robot Simulator with a command file:

### 1. Navigate to the Build Directory

```bash
cd build
```

### 2. Execute the Simulator
Run the simulator using:

```bash
./RobotSimulator ../tests/tests_data/test1.txt
```
Replace **../tests/test_data/test1.txt** with the path to any command file containing the instructions for the robot.

## Testing

Testing is performed using Google Test integrated via CMake.

### Run Tests
After building, you can run tests with:

```bash
make test
```
Or for verbose output:

```bash
make test ARGS="-V"
```
Alternatively, to view results for each test, run the test executable directly for detailed output:

```bash
./RunTests
```