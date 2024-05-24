#include "robot_simulator.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

RobotSimulator::RobotSimulator() : x(-1), y(-1), facing(""), directions{"NORTH", "EAST", "SOUTH", "WEST"} {}

void RobotSimulator::place(int x, int y, const std::string& facing) {
    if (x >= 0 && x < table_size && y >= 0 && y < table_size && 
        std::find(directions.begin(), directions.end(), facing) != directions.end()) {
        this->x = x;
        this->y = y;
        this->facing = facing;
    }
}

void RobotSimulator::move() {
    if (x == -1 || y == -1) return; // Ensure the robot has been placed
    int next_x = x, next_y = y;
    if (facing == "NORTH") next_y++;
    else if (facing == "SOUTH") next_y--;
    else if (facing == "EAST") next_x++;
    else if (facing == "WEST") next_x--;

    if (next_x >= 0 && next_x < table_size && next_y >= 0 && next_y < table_size) {
        x = next_x;
        y = next_y;
    }
}

void RobotSimulator::left() {
    if (facing.empty()) return; // Ensure the robot has been placed
    auto it = std::find(directions.begin(), directions.end(), facing);
    if (it != directions.end()) {
        facing = *(it == directions.begin() ? directions.end() - 1 : it - 1);
    }
}

void RobotSimulator::right() {
    if (facing.empty()) return; // Ensure the robot has been placed
    auto it = std::find(directions.begin(), directions.end(), facing);
    if (it != directions.end()) {
        facing = *(it == directions.end() - 1 ? directions.begin() : it + 1);
    }
}

std::string RobotSimulator::report() const {
    if (x == -1 || y == -1) return "Robot not placed";
    std::stringstream ss;
    ss << x << "," << y << "," << facing;
    return ss.str();
}

std::string RobotSimulator::getFacing() const {
    return facing;
}

void RobotSimulator::executeCommands(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "File not found: " << file_path << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        if (command == "PLACE") {
            int x, y;
            std::string f, dummy;
            std::getline(iss, dummy, ' '); // Skip space after PLACE
            std::getline(iss, dummy, ','); // Read x
            x = std::stoi(dummy);
            std::getline(iss, dummy, ','); // Read y
            y = std::stoi(dummy);
            iss >> f; // Read facing
            place(x, y, f);
        } else if (command == "MOVE") {
            move();
        } else if (command == "LEFT") {
            left();
        } else if (command == "RIGHT") {
            right();
        } else if (command == "REPORT") {
            std::cout << report() << std::endl;
        }
    }
}