#include "main.h"
#include "headers/globals.hpp"

// controllers
Controller master(pros::E_CONTROLLER_MASTER);
Controller partner(pros::E_CONTROLLER_PARTNER);

// motors
Motor right_mtr_1(3, MOTOR_GEARSET_6, false);
Motor right_mtr_2(4, MOTOR_GEARSET_6, false);
Motor left_mtr_1(1, MOTOR_GEARSET_6, true);
Motor left_mtr_2(2, MOTOR_GEARSET_6, true);

// motor groups
MotorGroup left_drive({left_mtr_1, left_mtr_2});
MotorGroup right_drive({right_mtr_1, right_mtr_2});

// encoders
// pros::ADIEncoder right_enc('A', 'B', true); // ports C and D
// pros::ADIEncoder left_enc('C', 'D', false); // ports A and B

// tracking wheels
// unset
// lemlib::TrackingWheel right_tracking_wheel(&right_enc, 3.25, 5);
// lemlib::TrackingWheel left_tracking_wheel(&left_enc, 3.25, -5);

// auton selector
int autonSelection = BLUE_1; // specifies the default auton selected

// odometry constants
float trackWidth = 8; // inches
float wheelDiameter = 2.5; // inches
float wheelRPM = 600; // rpm
float chasePower = 2; // unit uncertain

int autonomousPreSet = 0;