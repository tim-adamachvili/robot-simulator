cmake_minimum_required(VERSION 3.10)
project(RobotSimulatorProject)

# Enable Google Test
enable_testing()
add_subdirectory(lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(include)  # Assuming your headers are in the include directory

# Define the executable for the main application
add_executable(RobotSimulator src/main.cpp src/robot_simulator.cpp)

# Define the test executable
add_executable(RunTests tests/test_robot_simulator.cpp src/robot_simulator.cpp)
target_link_libraries(RunTests gtest gtest_main)

# Add the tests to be run by CMake's testing system
add_test(NAME RobotSimulatorTests COMMAND RunTests --gtest_brief=1)