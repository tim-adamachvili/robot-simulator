#include "gtest/gtest.h"
#include "robot_simulator.h"

TEST(RobotSimulatorTest, TestPlacement) {
    RobotSimulator robot;
    robot.place(0, 0, "NORTH");
    EXPECT_EQ(robot.report(), "0,0,NORTH");
}

TEST(RobotSimulatorTest, TestInvalidPlacementOutsideBounds) {
    RobotSimulator robot;
    robot.place(-1, 6, "NORTH");
    EXPECT_EQ(robot.report(), "Robot not placed");
}

TEST(RobotSimulatorTest, TestMoveWithinBounds) {
    RobotSimulator robot;
    robot.place(2, 2, "NORTH");
    robot.move();
    EXPECT_EQ(robot.report(), "2,3,NORTH");
}

TEST(RobotSimulatorTest, TestMoveOutsideBounds) {
    RobotSimulator robot;
    robot.place(0, 0, "SOUTH");
    robot.move();
    EXPECT_EQ(robot.report(), "0,0,SOUTH");
}

TEST(RobotSimulatorTest, TestTurnLeft) {
    RobotSimulator robot;
    robot.place(0, 0, "NORTH");
    robot.left();
    EXPECT_EQ(robot.getFacing(), "WEST");
}

TEST(RobotSimulatorTest, TestTurnRight) {
    RobotSimulator robot;
    robot.place(0, 0, "NORTH");
    robot.right();
    EXPECT_EQ(robot.getFacing(), "EAST");
}

TEST(RobotSimulatorTest, TestCommandSequence) {
    RobotSimulator robot;
    robot.place(1, 2, "EAST");
    robot.move();
    robot.move();
    robot.left();
    robot.move();
    EXPECT_EQ(robot.report(), "3,3,NORTH");
}

TEST(RobotSimulatorTest, TestFullSquareMovement) {
    RobotSimulator robot;
    robot.place(1, 1, "NORTH");
    robot.move();
    robot.right();
    robot.move();
    robot.right();
    robot.move();
    robot.right();
    robot.move();
    robot.right();
    EXPECT_EQ(robot.report(), "1,1,NORTH");
}

TEST(RobotSimulatorTest, TestBoundaryConditions) {
    RobotSimulator robot;
    robot.place(0, 0, "NORTH");
    for (int i = 0; i < 5; ++i) {  // Move five times, should be stopped at boundary
        robot.move();
    }
    EXPECT_EQ(robot.report(), "0,4,NORTH");
}