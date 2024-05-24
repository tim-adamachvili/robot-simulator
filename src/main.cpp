#include "robot_simulator.h"
#include <iostream>

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_commands_file>" << std::endl;
        return 1;
    }

    RobotSimulator simulator;
    simulator.executeCommands(argv[1]);
    return 0;
}