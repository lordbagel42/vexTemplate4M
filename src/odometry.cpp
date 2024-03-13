#include "headers/odometry.hpp"
#include "headers/globals.hpp"

// drivetrain
lemlib::Drivetrain drivetrain{
    &left_drive,   // left drivetrain motors
    &right_drive,  // right drivetrain motors
    trackWidth,    // track width
    wheelDiameter, // wheel diameter
    wheelRPM,      // wheel rpm
    chasePower     // chase power
};

// odometry
lemlib::OdomSensors sensors{
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // no horizontal tracking wheel
    nullptr, // no secondary horizontal tracking wheel
    nullptr  // no inertial sensor. sadly. :(
};

// lateral motion controller
lemlib::ControllerSettings
    lateralController(1,   // proportional gain (kP)
                      0,   // integral gain (kI)
                      0,   // derivative gain (kD)
                      3,   // anti windup
                      1,   // small error range, in inches
                      100, // small error range timeout, in milliseconds
                      3,   // large error range, in inches
                      500, // large error range timeout, in millisecondsF
                      20   // maximum acceleration (slew)
    );

// angular motion controller
lemlib::ControllerSettings
    angularController(8,   // proportional gain (kP)
                      0,   // integral gain (kI)
                      20,  // derivative gain (kD)
                      3,   // anti windup
                      1,   // small error range, in degrees
                      100, // small error range timeout, in milliseconds
                      3,   // large error range, in degrees
                      500, // large error range timeout, in milliseconds
                      0    // maximum acceleration (slew)
    );

// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController,
                        sensors);